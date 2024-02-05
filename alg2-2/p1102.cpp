//
// Created by QUAS on 2024/2/5.
//

// 需考虑诸如1 1 2 2的情况，也即出现重复数字的情况
// total需要开longlong

#include <bits/stdc++.h>
#define MAXN 200005
int arr[MAXN];

int main(){
    //freopen("./P1102_3.in", "r", stdin);
    memset(arr, 0, sizeof(arr));
    int n, c;
    std::cin >> n >> c;
    std::map<int, int> m;
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    long long total = 0;
    std::sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++){
        m[arr[i]]++;
    }
    int begin = 1;
    for(int i = 1; i <= n; i++){
        while(arr[i] - arr[begin] > c) begin++;
        if(arr[i] - arr[begin] == c){
            total = total + m[arr[begin]];
        }
    }
    printf("%lld", total);

    return 0;
}