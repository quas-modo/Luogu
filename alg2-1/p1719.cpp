//
// Created by QUAS on 2023/11/20.
//

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int a[130][130];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
}