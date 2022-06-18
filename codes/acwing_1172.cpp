#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#endif

const int N = 4e4 + 10, M = N*2;
// const int N = 40, M = N*2;

int jp[16][N];
int h[N], ecnt;
int depth[N];
int n, rt, m;

struct edge {
  int v, next;
} e[M];

void add(int u, int v) {
  e[++ecnt] = {v, h[u]};
  h[u] = ecnt;
}

void dfs(int u, int pa) {
  depth[u] = depth[pa] + 1;
  // printf("%d %d %d %d\n", u, depth[u], pa, depth[pa]);
  jp[0][u] = pa;
  FOR(i, 1, 15) {
    jp[i][u] = jp[i-1][jp[i-1][u]];
  }
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(v == pa) continue;
    dfs(v, u);
  }
}

int lca(int a, int b) {
  if(depth[a] < depth[b]) swap(a, b);
  _FOR(i, 15, 0)
    if(depth[jp[i][a]] >= depth[b])
      a = jp[i][a];
  if(a == b) return a;
  _FOR(i, 15, 0)
    if(jp[i][a] != jp[i][b]) {
      a = jp[i][a];
      b = jp[i][b];
    }
  return jp[0][a];
}

int main() {
  cin >> n;

  FOR(i, 1, n) {
    int a, b;
    cin >> a >> b;
    if(b == -1) {
      rt = a;
    } else {
      add(a, b);
      add(b, a);
    }
  }
  dfs(rt, 0);
  cin >> m;
  FOR(i, 1, m) {
    int a, b;
    cin >> a >> b;
    int pa = lca(a, b);
    if(pa == a) puts("1");
    else if(pa == b) puts("2");
    else puts("0");
  }
  return 0;
}
