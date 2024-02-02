//
// Created by QUAS on 2024/2/2.
//

#include <bits/stdc++.h>

#define MAXN 500005

struct cow {
    int x;
    int id;
} cows[MAXN];

int bucket[MAXN];

bool cmp(cow a, cow b) {
    return a.x < b.x;
}

int main() {
    int n;
    scanf("%d", &n);
    int index = 0;
    std::map<int, int> m;
    memset(cows, 0, sizeof(cows));
    memset(bucket, 0, sizeof(bucket));
    for (int i = 1; i <= n; i++) {
        int cx, cid;
        scanf("%d %d", &cx, &cid);
        cows[i].x = cx;
        // 离散化处理牛的标签
        if (m.find(cid) != m.end()) {
            cows[i].id = m[cid];
        } else {
            index++;
            m[cid] = index;
            cows[i].id = m[cid];
        }
    }
/*    for(int i = 1; i <= n; i++){
        printf("%d %d\n", cows[i].x, cows[i].id);
    }*/
    std::sort(cows + 1, cows + n + 1, cmp);
    int cost = INT_MAX;
    int begin = 1;
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (bucket[cows[i].id] == 0) num++;
        bucket[cows[i].id]++;

        while (num >= index && begin <= i) {
            if (cost > cows[i].x - cows[begin].x) {
                cost = cows[i].x - cows[begin].x;
            }
            bucket[cows[begin].id]--;
            if (bucket[cows[begin].id] == 0) num--;
            begin++;
        }
    }
    printf("%d", cost);
    return 0;
}