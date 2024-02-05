//
// Created by QUAS on 2024/1/16.
//

// 没有考虑到i=j的情况
// 处理i和j数值过大的情况->离散化处理
// 并查集的使用
// 未考虑足够大的数的问题->long long

#include <fstream>
#include <map>
#include <iostream>
using namespace std;

#define MAXN 200010

long long nq[MAXN][2];
long long eq[MAXN];
map<long long, long long> m;
long long ind = 0;

inline void init(long long n) {
  // 应该初始2*n个而不是n个，或者MAXN个
  for (long long i = 1; i <= 2 * n; i++) {
    eq[i] = i;
  }
}

long long find(long long x) {
  if (eq[x] == x) {
    return x;
  } else {
    return eq[x] = find(eq[x]);
  }
}

inline void merge(long long i, long long j) {
  eq[find(i)] = find(j);
}

long long discrete(long long a){
  if (auto search = m.find(a); search != m.end()){
    return search->second;
  }else{
    ind = ind + 1;
    m[a] = ind;
    return ind;
  }
}

int main() {
  freopen("./p1955_2.in","r",stdin);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    long long num = 0;
    bool flag = true;
    cin >> n;
    init(n);
    m.clear();
    ind = 0;
    for (int k = 1; k <= n; k++) {
      long long i, j, e;
      cin >> i >> j >> e;
      i = discrete(i);
      j = discrete(j);
      if (e == 1) { // xi = xj
        merge(i, j);
      } else { // e = 0 -> xi != xj
        num += 1;
        nq[num][0] = i;
        nq[num][1] = j;
      }
    }
    for (int k = 1; k <= num; k++) {
      // 把k写成num了
      long long m = find(nq[k][0]);
      long long n = find(nq[k][1]);
      //if (find(nq[k][0]) == find(nq[k][1])) {
      if (m == n){
        flag = false;
        break;
      }
    }
    if (flag) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}