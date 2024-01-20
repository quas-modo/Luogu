//
// Created by QUAS on 2024/1/16.
//

#include <bits/stdc++.h>

using namespace std;

struct Position{
  int a;
  int b;
}pos[20005];

//bool cmp(Position pos1, Position pos2){
//  if(pos1.a != pos2.a){
//    return pos1.a < pos2.a;
//  }else{
//    return pos1.b < pos2.b;
//  }
//}


int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    pos[i].a = a;
    pos[i].b = b;
  }
  auto cmp = [](const Position& pos1, const Position& pos2) {
    return std::tie(pos1.a, pos1.b) < std::tie(pos2.a, pos2.b);
  };
  sort(pos, pos + n, cmp);
  int sum = 0;
  int flag = INT_MIN;
  for(int i = 0; i < n; i++){
    //printf("%d \n", sum);
    if(flag > pos[i].b) continue;
    if(flag > pos[i].a){
      sum += pos[i].b - flag;
    }else{
      sum += pos[i].b - pos[i].a;
    }
    flag = pos[i].b;
  }
  printf("%d", sum);
}