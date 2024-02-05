//
// Created by QUAS on 2024/2/2.
//

#include <bits/stdc++.h>

#define MAXN 10005
int hMax[MAXN], hMin[MAXN];
struct position {
    int x;
    int y;
} pos[MAXN];

int main() {
    int l, h, r;
    memset(hMax, 0, sizeof(hMax));
    memset(hMin, 0, sizeof(hMin));
    memset(pos, 0, sizeof(pos));
    freopen("./p1904.in", "r", stdin);
    while (scanf("%d %d %d", &l, &h, &r) != -1) {
        for (int i = l; i <= r; i++) {
            if(hMax[i] < h){
                hMax[i] = h;
            }
            if(i < r && hMin[i] < h && l < i){
                hMin[i] = h;
            }

        }
    }
    int index = 0;
    int pre = 0;
    for (int i = 1; i < 10000; i++) {
        if(hMin[i] == hMax[i]){
            continue;
        }else{
            index++;
            pos[index].x = i;
            pos[index].y = pre;
            index++;
            pos[index].x = i;
            pos[index].y = (pre == hMax[i]) ? hMin[i] : hMax[i];
            pre = pos[index].y;
        }
    }
    for(int i = 1; i <= index; i++){
        if(i % 2 == 1){
            printf("%d ", pos[i].x);
        }else{
            printf("%d ", pos[i].y);
        }
    }


    return 0;
}