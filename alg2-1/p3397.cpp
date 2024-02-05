//
// Created by QUAS on 2024/1/15.
//

// i和j要想清楚
#include <bits/stdc++.h>

using namespace std;
int car[1005][1005];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for(int j = x1; j <= x2; j++){
      car[j][y1] += 1;
      car[j][y2+1] -= 1;
    }
  }
  for(int i = 1; i < n + 1; i++){
    int total = 0;
    for(int j = 1; j < n + 1; j++){
      total += car[i][j];
      printf("%d ", total);
    }
    printf("\n");
  }

  return 0;
}