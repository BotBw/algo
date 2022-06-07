#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

struct edge {
  int u, v, w;
  bool operator<(const edge &b) const {
    return w < b.w;
  }
};

const int N = 105;

int fa[N];
int g[N][N];

int find(int x) {
  return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int n;

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n;
  FOR(i, 1, n) fa[i] = i;
  
  FOR(i ,1 ,n)
    FOR(j ,1 ,n)
      cin >> g[i][j];

  vector<edge> es;
  FOR(i, 1, n) {
    FOR(j, i + 1, n) {
      es.push_back({i, j, g[i][j]});
    }
  }

  sort(es.begin(), es.end());

  int ans = 0;
  int cnt = 0;
  for(auto e : es) {
    int u = e.u, v = e.v, w = e.w;
    int x = find(u), y = find(v);
    if(x != y) {
      fa[y] = x;
      ans += w;
      cnt++;
      if(cnt == n - 1) break;
    }
  }
  cout << ans;
  return 0;
}
#endif