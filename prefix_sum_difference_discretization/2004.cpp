//
// Created by QUAS on 2024/1/29.
//

// 涉及边界的问题，可以通过多设置一列/一行来处理，这样就不用条件判断了
// 怎么会看不到c是边长，一开始弄成c+1是边长了

#include <bits/stdc++.h>

#define MAXN 1005
int val[MAXN][MAXN];
int sum[MAXN][MAXN];

int main() {
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &val[i][j]);
        }
    }
    memset(sum, 0, sizeof(int));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = val[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
/*            if(i != 0) sum[i][j] += sum[i - 1][j];
            if(j != 0) sum[i][j] += sum[i][j - 1];
            if(i != 0 && j != 0) sum[i][j] -= sum[i-1][j-1];*/
        }
    }
/*    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }*/
    int max = -INT_MAX;
    int index[2];
    for (int i = 1; i <= n - c + 1; i++) {
        for (int j = 1; j <= m - c + 1; j++) {
            int cur = sum[i + c - 1][j + c - 1] - sum[i - 1][j + c - 1] - sum[i + c - 1][j - 1] + sum[i - 1][j - 1];
/*            if (i > 0) cur -= sum[i - 1][j + c];
            if (j > 0) cur -= sum[i + c][j - 1];
            if (i > 0 && j > 0) cur += sum[i - 1][j - 1];*/
/*            printf("%d\n", cur);*/
            if (cur > max) {
                max = cur;
                index[0] = i;
                index[1] = j;
            }
        }
    }
    printf("%d %d", index[0], index[1]);

    return 0;
}