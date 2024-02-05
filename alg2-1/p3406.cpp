//
// Created by QUAS on 2024/1/30.
//

// 70: 未处理好大数
// sum = 1LL * a * b; 不然会超出int的处理范围

#include <bits/stdc++.h>

#define MAXN 100005

int a[MAXN], b[MAXN], c[MAXN], p[MAXN], dis[MAXN], sum[MAXN];

int main() {
    memset(a, 0, sizeof(int));
    memset(b, 0, sizeof(int));
    memset(c, 0, sizeof(int));
    memset(p, 0, sizeof(int));
    memset(dis, 0, sizeof(int));
    memset(sum, 0, sizeof(int));
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    for (int i = 1; i < m; i++) {
        int x, y;
        if (p[i] < p[i + 1]){
            x = p[i];
            y = p[i + 1];
        }else{
            x = p[i + 1];
            y = p[i];
        }
        dis[x] += 1;
        dis[y] -= 1;
    }
    int count = 0;
    for (int i = 1; i <= n; i++){
        count += dis[i];
        sum[i] = count;
    }
    long long money = 0;
    for (int i = 1; i < n; i++){
        long long ticket = 1LL * a[i] * sum[i];
        long long card = 1LL * b[i] * sum[i] + c[i];
        if(ticket < card){
            money += ticket;
        }else{
            money += card;
        }
    }
    printf("%lld", money);

    return 0;
}