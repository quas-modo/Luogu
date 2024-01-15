//
// Created by QUAS on 2024/1/15.
//

// 注意输入数据的下标(从1开始)
// sort的时间复杂度是O(nlogn)的复杂度，本题需要O(n)的复杂度
#include <bits/stdc++.h>
using namespace std;

int a[5000005];
int b[5000005];

int main(){
  int n, p;
  cin >> n;
  cin >> p;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  memset(b, 0, sizeof(b));
  for(int i = 1; i <= p; i++){
    int x, y, z;
    cin >> x >> y >> z;
    b[x] += z;
    b[y+1] -= z;
  }
  int total = 0;

  for(int i = 1; i <= n; i++){
    total += b[i];
    a[i] += total;
  }
  //sort的时间复杂度是nlog n
  //sort(a + 1, a + n + 1);
  int min = 0x3f3f3f;
  for(int i = 1; i <= n; i++){
    if(min > a[i]) min = a[i];
  }
  cout << min;
}