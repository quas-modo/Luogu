//
// Created by QUAS on 2024/2/7.
//

#include <bits/stdc++.h>
#define MAXN 1000005
#define MAXM 2005
int arr[MAXN];
int bkt[MAXN];

int main(){
    memset(arr, 0, sizeof(arr));
    memset(bkt, 0, sizeof(bkt));
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    int begin = 1;
    int num = 0;
    int min = INT_MAX;
    std::pair<int, int> ans;
    for(int i = 1; i <= n; i++){
        bkt[arr[i]]++;
        if(bkt[arr[i]] == 1){
            num++;
        }
        while(num >= m){
            int cost = i - begin;
            if(cost < min) {
                min = cost;
                ans = {begin, i};
            }
            bkt[arr[begin]]--;
            if(bkt[arr[begin]] == 0) num--;
            begin++;
        }
    }
    printf("%d %d", ans.first, ans.second);

    return 0;
}