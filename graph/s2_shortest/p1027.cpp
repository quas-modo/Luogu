//
// Created by QUAS on 2024/3/13.
//

// 如何根据矩形的任意三个点求出第四个点

#include <bits/stdc++.h>

#define N 1005
#define M 200000

using namespace std;
using pii = pair<int, int>;

struct City {
  int airport[4][2];
  int train;
} c[N];

int tot, head[N];
int flight, start, target;
double d[M];
bool visited[N];

struct Edge {
  int from, to, nxt;
  double val;
} e[M];

void addEdge(int from, int to, double val) {
  e[++tot].to = to;
  e[tot].val = val;
  e[tot].nxt = head[from];
  head[from] = tot;

  //printf("e: %d %d %.1lf\n", from, to, val);

  e[tot].from = from;
}

void buildTrain(City *city, int p) {
  int train = city->train;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      int disx = abs(city->airport[i][0] - city->airport[j][0]);
      int disy = abs(city->airport[i][1] - city->airport[j][1]);
      double dis = sqrt(pow(disx, 2) + pow(disy, 2));
      double val = train * dis;
      addEdge(p + i, p + j, val);
      addEdge(p + j, p + i, val);
    }
  }
}

// p和q表示最小坐标
void buildFlight(int a, int b) {
  City ca = c[a];
  City cb = c[b];
  int sa = (a - 1) * 4 + 1;
  int sb = (b - 1) * 4 + 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int disx = abs(ca.airport[i][0] - cb.airport[j][0]);
      int disy = abs(ca.airport[i][1] - cb.airport[j][1]);
      double dis = sqrt(pow(disx, 2) + pow(disy, 2));
      double val = dis * flight;
      addEdge(sa + i, sb + j, val);
      addEdge(sb + j, sa + i, val);
    }
  }
}

void calPos(City *city) {
  int x1 = city->airport[0][0];
  int y1 = city->airport[0][1];
  int x2 = city->airport[1][0];
  int y2 = city->airport[1][1];
  int x3 = city->airport[2][0];
  int y3 = city->airport[2][1];

  double dis1 = pow(x2 - x1, 2) + pow(y2 - y1, 2);
  double dis2 = pow(x3 - x2, 2) + pow(y3 - y2, 2);
  double dis3 = pow(x1 - x3, 2) + pow(y1 - y3, 2);

  if (dis1 > dis2 && dis1 > dis3) {
    ;
  } else if (dis2 > dis1 && dis2 > dis3) {
    int tmp = x1;
    x1 = x3;
    x3 = tmp;
    tmp = y1;
    y1 = y3;
    y3 = tmp;
  } else if (dis3 > dis1 && dis3 > dis2) {
    int tmp = x2;
    x2 = x3;
    x3 = tmp;
    tmp = y2;
    y2 = y3;
    y3 = tmp;
  }

  int x4 = x1 + x2 - x3;
  int y4 = y1 + y2 - y3;

  city->airport[3][0] = x4;
  city->airport[3][1] = y4;
  //printf("pos: %d %d\n", x4, y4);

}

void dijkstra(int u) {
  priority_queue<pii> q;
  q.push(pii(d[u] = 0, u));
  while (!q.empty()) {
    int v = q.top().second;
    q.pop();
    if (visited[v]) continue;
    visited[v] = true;
    for (int i = head[v]; i; i = e[i].nxt) {
      int w = e[i].to;
      double val = e[i].val;
      //printf("%d %d %.1lf %.1lf\n", e[i].from, e[i].to, d[w], val + d[v]);
      if (d[w] > val + d[v]) {
        d[w] = d[v] + val;
        q.push(pii(-d[w], w));
      }
    }
  }
}

int main() {
  //freopen("./p1027_4.in", "r", stdin);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    //printf("%d\n", i);
    tot = 0;
    memset(c, 0, sizeof(c));
    memset(e, 0, sizeof(e));
    memset(d, 0x43, sizeof(d));
    memset(head, 0, sizeof(head));
    memset(visited, 0, sizeof(visited));
    int S, A, B;
    scanf("%d%d%d%d", &S, &flight, &A, &B);
    for (int j = 1; j <= S; j++) {
      scanf("%d%d%d%d%d%d%d", &c[j].airport[0][0], &c[j].airport[0][1], &c[j].airport[1][0], &c[j].airport[1][1],
            &c[j].airport[2][0], &c[j].airport[2][1], &c[j].train);
      calPos(&c[j]);
    }
    // 建立城市内部的铁路的边
    for (int j = 1; j <= S; j++) {
      buildTrain(&c[j], (j - 1) * 4 + 1);
    }
    // 建立城市之间的飞机的边
    for (int a = 1; a <= S; a++) {
      for (int b = a + 1; b <= S; b++) {
        buildFlight(a, b);
      }
    }
    // 建立虚拟起始点和虚拟终止点的边
    start = 4 * S + 1;
    target = 4 * S + 2;
    for (int j = 0; j < 4; j++) {
      addEdge(start, (A - 1) * 4 + 1 + j, 0);
      addEdge((A - 1) * 4 + 1 + j, start, 0);
      addEdge(target, (B - 1) * 4 + 1 + j, 0);
      addEdge((B - 1) * 4 + 1 + j, target, 0);
    }
    dijkstra(start);

    printf("%.1lf\n", d[target]);
  }
  return 0;
}