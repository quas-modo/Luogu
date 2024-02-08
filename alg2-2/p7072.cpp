//
// Created by QUAS on 2024/2/8.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> rHeap;  //小顶堆
priority_queue<int, vector<int>, less<int>> lHeap;

int main(){
    int n, w, num;
    int l = 0, r = 0; // 假设左堆是小堆，右堆是大堆
    scanf("%d %d", &n, &w);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num);
        // 将当前的数加入左右堆中
        if( lHeap.empty() ||  num > lHeap.top()){
            rHeap.push(num);
            r++;
        }else{
            lHeap.push(num);
            l++;
        }
        // 控制最小堆的答案是所求
        int rNum = i * w / 100;
        rNum = max(1, rNum);
        while(r > rNum){
            int tmp = rHeap.top();
            rHeap.pop();
            lHeap.push(tmp);
            r--;
        }
        while(r < rNum){
            int tmp = lHeap.top();
            lHeap.pop();
            rHeap.push(tmp);
            r++;
        }
        printf("%d ", rHeap.top());
    }

    return 0;
}