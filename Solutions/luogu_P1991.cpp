#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

int S, P;

const int maxp = 505;

struct cord {
  int x, y;
} cor[maxp];

double dist(int i, int j) {
  double dx = cor[i].x - cor[j].x;
  double dy = cor[i].y - cor[j].y;
  return sqrt(dx*dx+dy*dy);
}

struct edge {
  int u, v;
  double dis;
  bool operator<(const edge &b) const {
    return dis < b.dis;
  }
} e[maxp*maxp/2];
int ecnt;
int STOP;

int fa[maxp], sz[maxp];

int find(int x) {
  return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
void unionn(int x, int y) {
  int xx = find(x);
  int yy = find(y);
  if(sz[xx] >= sz[yy]) {
    fa[yy] = xx;
  } else {
    fa[xx] = yy;
  }
}
bool query(int x, int y) {
  return find(x) == find(y);
}
double ans;
void kruskal() {
  FOR(i, 1, P) {
    fa[i] = i;
    sz[i] = 1;
  }
  int stop = 0;
  sort(e+1, e+1+ecnt);
  FOR(i, 1, ecnt) {
    if(!query(e[i].u, e[i].v)) {
      ans = max(ans, e[i].dis);
      unionn(e[i].u, e[i].v);
      stop++;
      if(stop == STOP) break;
    }
  }
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  scanf("%d %d", &S, &P);
  FOR(i, 1, P) {
    scanf("%d %d", &cor[i].x, &cor[i].y);
  }
  FOR(i, 1, P) {
    FOR(j, i + 1, P) {
      e[++ecnt] = {i, j, dist(i, j)};
    }
  }
  STOP = P - S;
  kruskal();
  printf("%.2f", ans);
  return 0;
}
#endif