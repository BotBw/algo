#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int n, k;

const int maxn = 1e3+1;

struct cord {
  int x, y;
} cor[maxn];

struct edge {
  int u, v;
  double w;
  bool operator<(const edge &b) const {
    return w < b.w;
  }
} e[maxn*maxn/2];
int ecnt;

double dist(int i, int j) {
  double dx = cor[i].x - cor[j].x;
  double dy = cor[i].y - cor[j].y;
  return sqrt(dx*dx + dy*dy);
}

int fa[maxn], sz[maxn];

void init() {
  FOR(i, 1, n) {
    fa[i] = i;
    sz[i] = 1;
  }
}

int find(int x) {
  return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void unionn(int i, int j) {
  int ii = find(i);
  int jj = find(j);
  if(sz[ii] >= sz[jj]) {
    fa[jj] = ii;
    sz[ii] += sz[jj];
  } else {
    fa[ii] = jj;
    sz[jj] += sz[ii];
  }
}

bool query(int i, int j) {
  return find(i) == find(j);
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> k;
  FOR(i, 1, n) {
    cin >> cor[i].x >> cor[i].y;
  }
  init();
  FOR(i, 1, n) {
    FOR(j, i+1, n) {
      e[++ecnt] = {i, j, dist(i, j)};
    }
  }
  sort(e+1, e+ecnt+1);
  int STOP = n - k + 1;
  int stop = 0;
  int id = 0;
  FOR(i, 1, ecnt) {
    id = i;
    if(!query(e[i].u, e[i].v)) {
      unionn(e[i].u, e[i].v);
      stop++;
      if(stop == STOP) break;
    }
  }
  printf("%.2f", e[id].w);
  return 0;
}
#endif