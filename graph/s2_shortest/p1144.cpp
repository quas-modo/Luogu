//
// Created by QUAS on 2024/3/13.
//

// 自环应该不会包括吧。如果带有自环，就不是最短路了。

#include <bits/stdc++.h>

#define N 1000005
#define M 2000005

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

void dijkstra(int u){
    priority_queue<pii> q;
    q.push(pii(- d[u], u));
    while(!q.empty()){
        int v = q.top().second; q.pop();
        ans[v] += 1;
        ans[v] = (ans[v]) % 100003;
        for(int i = head[v]; i; i = e[i].nxt){
            int w = e[i].to;
            if(d[w] >= d[v] + 1){ // 相同的要放进去
                d[w] = d[v] + 1;
                q.push(pii(-d[w], w));
            }
        }
    }
}

int main() {
    //freopen("./p1144_1.in", "r", stdin);
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(e, 0, sizeof(e));
    memset(visited, 0, sizeof(visited));
    memset(ans, 0, sizeof(ans));
    memset(d, 0x3f, sizeof(d)); d[1] = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x == y){
            if(x == 1) d[1] += 1;
        }else{
            addEdge(x, y, 1);
            addEdge(y, x, 1);
        }
    }

    dijkstra(1);
    ans[1] = d[1];
    if(!ans[1]) ans[1] = 1;

    for(int i = 1; i <= n; i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}