//
// Created by QUAS on 2024/3/21.
//

#include <bits/stdc++.h>
#define N 300005
#define M 25
#define MOD 998244353

struct Edge {
  int to, nxt, val;
} e[N << 1];
int tot, head[N];
void addEdge(int from, int to, int val) {
  e[++tot].to = to;
  e[tot].val = val;
  e[tot].nxt = head[from];
  head[from] = tot;
}

void swap(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}

long long powk[N][55];
long long prek[N][55];
void initPow(int maxDep) {
  for (int i = 1; i <= maxDep; i++) {
    powk[i][0] = 1;
    for (int j = 1; j <= 50; j++) {
      powk[i][j] = (powk[i][j - 1] * i) % MOD;
    }
  }
  for (int i = 1; i <= 50; i++) {
    for (int j = 1; j <= maxDep; j++) {
      prek[j][i] = prek[j - 1][i] + powk[j][i];
      prek[j][i] = prek[j][i] % MOD;
    }
  }
}

int fa[N][M], dep[N];
void dfs(int x, int fath, int depth) {
  dep[x] = depth;
  fa[x][0] = fath;
  for (int i = 1; i <= 20; i++) {
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  }
  for (int i = head[x]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fath) continue;
    dfs(v, x, depth + 1);
  }
}
int lca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  for (int i = 0, tmp = dep[y] - dep[x]; tmp; i++, tmp >>= 1){ // 为什么从i = 0开始？ 因为fa[x][0]存的是父节点，不是自身
    if (tmp & 1) y = fa[y][i];
  }
  if (x == y) return x;
  for (int i = 20; i >= 0; i--) { // 这里为什么有 i = 0
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return fa[x][0];
}

int main() {
  //freopen("./p4427.in", "r", stdin);
  memset(e, 0, sizeof(e));
  tot = 0;
  memset(head, 0, sizeof(head));
  memset(fa, 0, sizeof(fa));
  memset(dep, 0, sizeof(dep));
  memset(powk, 0, sizeof(powk));
  memset(prek, 0, sizeof(prek));

  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int v, w;
    scanf("%d%d", &v, &w);
    addEdge(v, w, 1);
    addEdge(w, v, 1);
  }

  dfs(1, 0, 0);
  int maxDep = 0;
  for (int i = 1; i <= n; i++) {
    if (maxDep < dep[i]) maxDep = dep[i];
  }
  initPow(maxDep);

  int m;
  scanf("%d", &m);
  for (int t = 1; t <= m; t++) {
    int i, j, k;
    scanf("%d %d %d", &i, &j, &k);

    int a = lca(i, j);
    long long sum;
    if (a != 1) {
      sum = prek[dep[i]][k] + prek[dep[j]][k] - prek[dep[a]][k] - prek[dep[a] - 1][k];
    }else {
      sum = prek[dep[i]][k] + prek[dep[j]][k] - prek[dep[a]][k];
    }
    while (sum < 0) sum += MOD;
    sum = sum % MOD;

    printf("%lld\n", sum);
  }

  return 0;
}