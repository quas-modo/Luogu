# Luogu
personal records of Luogu

注意事项总结如下：

# 通用
1. 数值过大的时候，使用longlnog；
```
long long sum = 0ll;
```
2. 数值过大的时候，根据题目提示，及时做mod的处理
```
#define MOD 998244353
```
3. pow的自己实现方式
4. stack-入栈和出栈写在一起
```cpp
instack[x] = true, s[++top] = x;
y = s[top--], instack[y] = false;
```


# 图
1. 无向图的边数组要开两倍大，不然在读入的时候就会造成段错误 

```
例如，1≤N≤106，1≤M≤2×1061≤M≤2×10^6^。 e应该开4000005
或者直接写成这样就不会忘了。

struct Edge {
  int to, nxt, val;
} e[N << 1];
```



## 树上存储结构和技巧
### 链式前向星
存储结构: Edge, head, tot

### 树上前缀和
如在处理dep时，可以顺带处理前缀的dis或者weight（加权的或者带次方）的，便于后续查询使用

## 最短路
### Dijkstra总结
1. 找到点（判断是否已访问）
2. 更新访问状态，即将点放入S点集中
3. 更新相连接的点的最短

## 最小生成树
n个顶点，n-1条边
边权最小的边一定在mst中
### prim
1. 找到点（判断是否已访问）
2. 更新访问状态，即将点放入S点集中
3. 更新与树最近的点【和Dijkstra算法的不同之处】

### kruskal
存储结构ufs union find
使用并查集实现。
使用无向边的struct，每次加入边权最小、减少联通块数量的边。

## 树的直径
两次dfs或者bfs求得。

## lca
### 倍增算法
存储结构：fa, dep
1. 建树
2. 跳到同一深度
3. 一起向上跳，直到相遇