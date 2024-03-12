//
// Created by QUAS on 2024/3/11.
//

#include <bits/stdc++.h>

int main(){
  freopen("./s1_2.in", "w", stdout);
  int n = 100;
  int m = 40;

  printf("%d %d\n", n, m);
  for(int i = 1; i <= m; i++){
    int a = rand() % n;
    int b = rand() % n;
    printf("%d %d\n", a + 1, b + 1);
  }

  return 0;
}