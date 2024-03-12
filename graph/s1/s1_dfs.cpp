//
// Created by QUAS on 2024/3/11.
//

#include <bits/stdc++.h>

using namespace std;

#define N 10005
#define M 2*N

int tot, head[N], visited[N];

struct Edge {
  int to, nxt, val;
} e[M];

void addEdge(int from, int to, int val) {
  e[++tot].to = to;
  e[tot].nxt = head[from];
  e[tot].val = val;
  head[from] = tot;
}

void dfs(int ver) {
  // 已访问则退出，未访问则标记（更改状态）
  if(visited[ver] == 1) return;
  visited[ver] = 1;
  for (int i = head[ver]; i; i = e[i].nxt) {
    int y = e[i].to;
    dfs(y);
  }
}

int main() {
  freopen("./s1_2.in", "r", stdin);
  tot = 0;
  memset(head, 0, sizeof(head));
  memset(visited, 0, sizeof(visited));
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    addEdge(a, b, 1);
    addEdge(b, a, 1);
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
      sum++;
    }
  }
  printf("%d", sum);
}