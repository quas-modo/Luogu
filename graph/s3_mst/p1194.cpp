//
// Created by QUAS on 2024/3/15.
//

#include<bits/stdc++.h>

#define N 505
#define M 5000005
using namespace std;

int tot;
struct Edge_ {
    int x, y, v;
} e[M];

void addEdge(int x, int y, int v) {
    e[++tot].x = x;
    e[tot].y = y;
    e[tot].v = v;
}

int ufs[N];

int get(int i) {
    return ufs[i] == i ? i : ufs[i] = get(ufs[i]);
}

void merge(int x, int y) {
    int fx = get(x), fy = get(y);
    if (fx == fy) return;
    ufs[fx] = fy;
}

int cmp(const Edge_ &e1, const Edge_ &e2) {
    return e1.v < e2.v;
}

int kruskal(int n) {
    sort(e, e + tot + 1, cmp); // last是开区间，不能忘了+1
    int sum = 0, cnt = 0;
    for (int i = 1; i <= tot; i++) {
        Edge_ edge = e[i];
        int x = edge.x, y = edge.y, v = edge.v;
        if(get(x) == get(y)) continue;
        merge(x, y);
        sum += v;
        cnt++;
        if(cnt >= n - 1) break;
    }
    return sum;
}


int main() {
    //freopen("./p1194.in", "r", stdin);
    memset(e, 0, sizeof(e));
    for (int i = 0; i < N; i++) {
        ufs[i] = i;
    }
    tot = 0;

    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= b; j++) {
            int k;
            scanf("%d", &k);
            if (i >= j || k == 0) continue; // 自己和自己没有优惠，并且如果k=0也是没有优惠的
            addEdge(i, j, k);
        }
    }
    for (int i = 1; i <= b; i++) {
        addEdge(0, i, a);
    }

    int sum = kruskal(b + 1);
    printf("%d", sum);

    return 0;
}