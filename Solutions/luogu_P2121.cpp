#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int n, m, K;

const int maxm = 1e5+5;
const int maxn = 1e5+5;
struct edge {
  int u ,v, w;
  bool operator>(const edge &b) const {
    return w > b.w;
  }
} e[maxm];
int ecnt;

int fa[maxn];
int sz[maxn];

int find(int x) {
  return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void unionn(int x, int y) {
  int xx = find(x);
  int yy = find(y);
  if(sz[xx] >= sz[yy]) {
    fa[yy] = xx;
    sz[xx] += sz[yy];
  } else {
    fa[xx] = yy;
    sz[yy] += sz[xx];
  }
}

bool query(int x, int y) {
  return find(x) == find(y);
}

void init_u() {
  FOR(i, 1, n) {
    fa[i] = i;
    sz[i] = 1;
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m >> K;
  init_u();
  FOR(i, 1, m) {
    int u ,v ,w;
    cin >> u >> v >> w;
    e[++ecnt] = {u, v, w};
  }
  sort(e+1, e+ecnt+1, greater<edge>());
  int k = 0;
  int ans = 0;
  FOR(i, 1, m) {
    if(!query(e[i].u, e[i].v)) {
      unionn(e[i].u, e[i].v);
      ans += e[i].w;
      k++;
      if(k == K) break;
    }
  }
  cout << ans;
  return 0;
}
#endif