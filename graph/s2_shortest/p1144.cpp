//
// Created by QUAS on 2024/3/13.
//

// 自环应该不会包括吧。如果带有自环，就不是最短路了。
// 边的数组应该开2倍
// 不要忘了%的处理

#include <bits/stdc++.h>

#define N 1000005
#define M 4000005

using namespace std;
using pii = pair<int, int>;

int tot, head[N], visited[N], ans[N], d[N];
struct Edge {
    int to, nxt, val;
} e[M];

void addEdge(int from, int to, int val) {
    e[++tot].to = to;
    e[tot].val = val;
    e[tot].nxt = head[from];
    head[from] = tot;
}

void dijkstra(int u) {
    priority_queue<pii> q;
    q.push(pii(d[u] = 1, u));
    ans[u] = 1;
    while (!q.empty()) {
        int v = q.top().second;
        q.pop();

        if (visited[v]) continue;
        visited[v] = 1;
        for (int i = head[v]; i; i = e[i].nxt) {
            int w = e[i].to;
            if (d[w] > d[v] + 1) { // 相同的要放进去
                d[w] = d[v] + 1;
                ans[w] = ans[v];
                q.push(pii(-d[w], w));
            }else if(d[w] == d[v] + 1){
                ans[w] = (ans[w] + ans[v]) % 100003;
            }
        }
    }
}

int main() {
    //freopen("./P1144_6.in", "r", stdin);
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(e, 0, sizeof(e));
    memset(visited, 0, sizeof(visited));
    memset(ans, 0, sizeof(ans));
    memset(d, 0x3f, sizeof(d));
    int n, m, ans_1 = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x == y) {
            if (x == 1) ans_1 += 1;
        } else {
            addEdge(x, y, 1);
            addEdge(y, x, 1);
        }
    }

    dijkstra(1);

    if (ans_1 == 0) {
        ans[1] = 1;
    } else {
        ans[1] = ans_1;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}