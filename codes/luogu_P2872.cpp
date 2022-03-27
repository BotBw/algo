#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxn = 1005;
int n, m;

struct cord {
  int x, y;
} cor[maxn];

double dist(int i, int j) {
  double dx = cor[i].x - cor[j].x;
  double dy = cor[i].y - cor[j].y;
  return sqrt(dx*dx + dy*dy);
}

double graph[maxn][maxn];

struct node {
  int x;
  double dis;
  bool operator<(const node &b) const {
    return dis > b.dis;
  }
};

double dis[maxn];
bool vis[maxn];

double prim(int S) {
  double treeLen = 0;
  dis[S] = 0;
  priority_queue<node> q;
  q.push({S, 0});

  while(!q.empty()) {
    auto least = q.top();
    q.pop();
    if(vis[least.x]) continue;
    vis[least.x] = true;
    treeLen += least.dis;
    int u = least.x;
    FOR(v, 1, n) {
      if(graph[u][v] != -1) {
        if(dis[v] > graph[u][v]) {
          dis[v] = graph[u][v];
          q.push({v, graph[u][v]});
        }
      }
    }
  }
  return treeLen;
}

void init() {
  FOR(i, 1, n) {
    FOR(j, 1, n) {
      graph[i][j] = -1;
    }
  }
  FOR(i, 1, n) {
    dis[i] = 1e20;
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  init();
  FOR(i, 1, n) {
    cin >> cor[i].x >> cor[i].y;
  }
  FOR(i, 1, n) {
    FOR(j, i+1, n) {
      graph[i][j] = graph[j][i] = dist(i, j);
    }
  }
  FOR(i, 1, m) {
    int u, v;
    cin >> u >> v;
    graph[u][v] = graph[v][u] = 0;
  }
  printf("%.2f", prim(1));
  return 0;
}
#endif