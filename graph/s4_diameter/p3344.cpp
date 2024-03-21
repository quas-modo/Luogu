//
// Created by QUAS on 2024/3/16.
//

#include <bits/stdc++.h>
#define N 200005
#define M 400005
using namespace std;

long dis[M];
int n, tot, head[N], visited[M], num[M];
long maxDis, curDis;
struct Edge {
  int from, to, nxt, val;
} e[M];
void addEdge(int from, int to, int val) {
  e[++tot].to = to;
  e[tot].from = from;
  e[tot].val = val;
  e[tot].nxt = head[from];
  head[from] = tot;
}

void dfs(int x, int fa, long dis[]) {
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    int val = e[i].val;
    if (y == fa) {
      continue;
    }
    dis[y] = dis[x] + val;
    dfs(y, x, dis);
  }
}

int dfs2(int x, int fa) {
  bool flag = false;
  int ret = 0;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    int val = e[i].val;
    if (y == fa) {
      continue;
    }
    flag = true;
    curDis += val;
    int leaf = dfs2(y, x);
    num[i] += leaf;
    ret += leaf;
    curDis -= val;
  }
  if (!flag) {
    if (curDis == maxDis) {
      return 1;
    }
  }
  return ret;
}

int main() {
  //freopen("./p3344.in", "r", stdin);
  memset(dis, 0, sizeof(dis));
  memset(visited, 0, sizeof(visited));
  memset(num, 0, sizeof(num));
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    addEdge(a, b, c);
    addEdge(b, a, c);
  }
  dfs(1, 0, dis);
  maxDis = 0;
  vector<int> indexes;
  for (int i = 1; i <= n; i++) {
    if (maxDis < dis[i]) {
      maxDis = dis[i];
      indexes.clear();
      indexes.push_back(i);
    } else if (maxDis == dis[i]) {
      indexes.push_back(i);
    }
  }
  memset(dis, 0, sizeof(dis));
  dfs(indexes[0], 0, dis);
  for (int i = 1; i <= n; i++) {
    if (maxDis < dis[i]) {
      maxDis = dis[i];
    }
  }
  printf("%ld\n", maxDis);
  for (int i: indexes) {
    curDis = 0;
    dfs2(i, 0);
  }
  for (int i = 1; i <= tot; i++) {
    visited[(i + 1) / 2] += num[i];
  }
  sort(visited, visited + M);
  long long sum = 0;
  for (int i = M - 1; i >= 0; i--) {
    if (visited[i] != visited[M - 1]) break;
    sum++;
  }
  printf("%lld", sum);

  return 0;
}