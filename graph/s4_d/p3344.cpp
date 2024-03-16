//
// Created by QUAS on 2024/3/16.
//

#include <bits/stdc++.h>
#define N 200005
#define M 400005
using namespace std;
using pli = pair<long long, int>;

int n, tot, head[N];
struct Edge {
  int to, nxt, val;
} e[M];
void addEdge(int from, int to, int val) {
  e[++tot].to = to;
  e[tot].val = val;
  e[tot].nxt = head[from];
  head[from] = tot;
}

pli dfs(int x, int fa) {
  long long dis = 0;
  int point = x;
  for (int i = head[x]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (to == fa) continue;
    pli sub = dfs(to, x);
    long long cur = sub.first + e[i].val;
    if (dis < cur) {
      dis = cur;
      point = sub.second;
    }
  }
  return pli(dis, point);
}

int main() {
  freopen("./p3344.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    addEdge(a, b, c);
    addEdge(b, a, c);
  }
  pli ret = dfs(1, 0);
  ret = dfs(ret.second, 0);
  printf("%lld", ret.first);
  return 0;
}