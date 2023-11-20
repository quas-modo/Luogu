//
// Created by QUAS on 2023/11/20.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int n, m;
  int a[100005];
  cin >> n;
  for(int i = 1; i < n + 1; i++) cin >> a[i];
  cin >> m;
  long long sum[n];
  long long s = 0;
  sum[0] = 0;
  for(int i = 1; i < n + 1; i++){
    s += a[i];
    sum[i] = s;
  }
  for(int i = 0; i < m; i++){
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << endl;
  }
}