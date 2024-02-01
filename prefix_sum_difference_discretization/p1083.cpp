//
// Created by QUAS on 2024/2/1.
//

// int的范围2147483647
// 二分查找（怎么书写？）、差分
// sum 要开 long long

#include <bits/stdc++.h>

#define MAXN 1000005

int r[MAXN], d[MAXN], s[MAXN], t[MAXN];
long long rent[MAXN], diff[MAXN];

bool isSatisfied(int x){
    memset(rent, 0, sizeof(rent));
    memset(diff, 0, sizeof(diff));
    long long sum = 0;
    for(int i = 1; i <= x; i++){
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }
    for(int i = 1; i < MAXN; i++){
        sum += diff[i];
        rent[i] = sum;
    }
    for(int i = 1; i < MAXN; i ++){
        if(r[i] < rent[i]){
            return false;
        }
    }
    return true;
}

int main(){
    //freopen("./p1083_21.in", "r", stdin);
    int n, m;
    memset(r, 0, sizeof(r));
    memset(d, 0, sizeof(d));
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &r[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &d[i], &s[i], &t[i]);
    }
    int begin = 1;
    int end = m;
    while(begin < end){
        int mid = begin + ((end - begin) >> 1);
        if(isSatisfied(mid)){
            begin = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    if(begin == m){
        printf("0");
    }else{
        printf("-1\n");
        if(isSatisfied(begin)){
            printf("%d", begin + 1);
        }else{
            printf("%d", begin);
        }
    }
    return 0;
}