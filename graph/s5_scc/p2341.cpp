//
// Created by QUAS on 2024/3/25.
//

#include <bits/stdc++.h>
#define N 10005
#define M 50005
using namespace std;
int n, m;
int head[N], tot;
struct Edge{
    int to, nxt;
}e[M];
void addEdge(int from, int to) {
    e[++tot].to = to;
    e[tot].nxt = head[from];
    head[from] = tot;
}

int dfn[N], low[N], cnt, top, s[N], nscc, bel[N];
bool instack[N];
vector<int> scc[N];
void tarjan(int x) {
    dfn[x] = low[x] = ++cnt;
    instack[x] = true, s[++top] = x; // 入栈和出栈写在一起
    for (int i = head[x]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (!dfn[v]) { // 树边
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if (instack[v]) {
            low[x] = min(low[x], dfn[v]);
        }
    }
    if (dfn[x] == low[x]) {
        nscc++;
        int y;
        do{
            y = s[top--], instack[y] = false;
            bel[y] = nscc;
            scc[nscc].push_back(y);
        }while(x != y);
    }
}



int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }


    // 查看建图的结果
    for (int i = 1; i <= nscc; i++) {
        for (int j : scc[i]) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // 构建DAG





    return 0;
}