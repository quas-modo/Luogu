//
// Created by QUAS on 2024/2/2.
//

#include <bits/stdc++.h>

#define MAXN 100005
int a[MAXN], diff[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    diff[1] = a[1];
    long long pos = 0LL;
    long long neg = 0LL;
    for(int i = 2; i <= n; i++){
        diff[i] = a[i] - a[i - 1];
        if(diff[i] < 0){
            neg += diff[i];
        }else{
            pos += diff[i];
        }
    }
    printf("%lld\n", std::max(abs(neg), pos));
    printf("%lld\n", abs(neg + pos) + 1);


    return 0;
}