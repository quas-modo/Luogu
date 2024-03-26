//
// Created by QUAS on 2024/3/26.
//

#include <bits/stdc++.h>

using namespace std;

#define N 10005
#define M 100005

int w[N], head[N], tot;
struct Edge {
    int to, nxt;
} e[M << 2];

void addEdge(int from, int to) {
    e[++tot].to = to;
    e[tot].nxt = head[from];
    head[from] = tot;
}

int dfn[N], low[N], dfsn;
int top, s[N], sccn, bel[N];
bool ins[N];
vector<int> scc[N];

void tarjan(int x) {
    dfn[x] = low[x] = ++dfsn;
    s[++top] = x;
    ins[x] = true;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        int y;
        sccn++; // todo: 这里应该写在外面，这整个处理的是一个scc，别写错别写错别写错
        do {
            y = s[top--];
            ins[y] = false;
            scc[sccn].push_back(y);
            bel[y] = sccn;
        } while (x != y);
    }
}

int n, m;
int a;
int u, v;

int sw[N], shead[N], stot;
Edge se[M << 2];

void addsEdge(int from, int to) {
    se[++stot].to = to;
    se[stot].nxt = shead[from];
    shead[from] = stot;
    //printf("dag: %d %d\n", from, to);
}

int in[N];

long long dfs(int x, int fa) {
    long long weight = sw[x];
    long long sub = 0;
    for (int i = shead[x]; i; i = se[i].nxt) {
        int y = se[i].to;
        if (y != fa) {
            long long r = dfs(y, x);
            sub = max(sub, r);
        }
    }
    return weight + sub;
}

int main() {
    //freopen("./P3387_1.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        w[i] = a;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    // construct dag
    for (int i = 1; i <= sccn; i++) {
        //printf("i: %d\n", i);
        for (int j: scc[i]) {
            sw[i] += w[j];
            //printf("j, bel[j]: %d %d\n", j, bel[j]);
            for (int k = head[j]; k; k = e[k].nxt) {
                int x = e[k].to;
                if (bel[j] != bel[x]) {
                    //printf("origin: %d %d\n", j, x);
                    addsEdge(bel[j], bel[x]); // todo: 这里，是找到两个点的所属scc编号，不是bel[k]
                }
            }
        }
    }


    // 计算入度
    for (int i = 1; i <= stot; i++) {
        int x = se[i].to;
        in[x]++;
    }

    long long ans = 0;
    for (int i = 1; i <= sccn; i++) {
        if (in[i] == 0) {
            long long ret = dfs(i, 0);
            ans = max(ans, ret);
        }
    }

    printf("%lld", ans);

    return 0;
}