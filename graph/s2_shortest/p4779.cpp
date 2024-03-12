//
// Created by QUAS on 2024/3/12.
//

// dijkstra总结：1. 找到点（判断是否已访问） 2.更新访问状态，将点放入S点集中 3，更新相连接的点的最短

#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define N 100005
#define M 200005
using namespace std;

using pii = std::pair<int, int>;

int tot, head[N], d[N], visited[N];

struct Edge{
    int to, nxt, val, from;
}e[M];

void addEdge(int from, int to, int val){
    e[++tot].to = to;
    e[tot].val = val;
    e[tot].nxt = head[from];
    head[from] = tot;

    e[tot].from = from;
}

void dijkstra(int u, int n){
    d[u] = 0;
    for(int i = 1; i <= n; i++){
        int v = 0; // 不用声明min，直接更新v即可
        for(int j = 1; j <= n; j++){
            if(visited[j]) continue;
            if(v == 0 || d[j] < d[v]){
                v = j;
            }
        }
        visited[v] = 1;
        for(int j = head[v]; j; j = e[j].nxt){
            int y = e[j].to;
            int val = e[j].val;
            if(d[y] > d[v] + val){
                d[y] = d[v] + val;
            }
        }
    }
}

void dijkstra_dump(int u){
    priority_queue<pii> q;
    q.push(pii(d[u] = 0, u));
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        if(visited[v]) continue;
        visited[v] = 1; // don't forget to update
        for(int i = head[v]; i; i = e[i].nxt){
            int w = e[i].to;
            if(d[w] > d[v] + e[i].val){
                d[w] = d[v] + e[i].val;
                q.push(pii(-d[w], w));
            }
        }
    }

}

void checkGraph(){
    printf("\n");
    for(int i = 1; i <= tot; i++){
        printf("%d %d %d\n", e[i].from, e[i].to, e[i].val);
    }
}

int main(){
    //freopen("./p4779_1.in", "r", stdin);
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(e, 0, sizeof(e));
    memset(d, 0x3f, sizeof(d));
    memset(visited, 0, sizeof(visited));
    int n = 0, m = 0, s = 0;
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    dijkstra_dump(s);
    for(int i = 1; i <= n; i++){
        printf("%d ", d[i]);
    }

    return 0;
}