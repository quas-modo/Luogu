//
// Created by QUAS on 2024/3/11.
//

#include <bits/stdc++.h>

using namespace std;

#define N 10005
#define M 2*N

int ufs[N];

int get(int x) {
  return ufs[x] == x ? x : ufs[x] = get(ufs[x]);
}

void merge(int x, int y) {
  int fx = get(x), fy = get(y);
  if (fx == fy) return;
  ufs[fx] = fy;
}

int main() {
  freopen("./s1_2.in", "r", stdin);

  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++){
    ufs[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    merge(a, b);
  }

  int sum = 0;
  for (int i = 1; i <= n; i++){
    if(ufs[i] == i) sum++;
  }
  printf("%d", sum);

  return 0;
}