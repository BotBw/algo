#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 105, src = 0;
int g[N][N];
int lvl[N];
int m, n;

int dis[N];
bool inq[N];

void spfa(int lo, int hi) {
  memset(dis, 0x3f, sizeof dis);
  memset(inq, 0, sizeof inq);
  queue<int> q;
  inq[src] = 1;
  dis[src] = 0;
  q.push(src);

  while(!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = 0;

    FOR(v, 0, n) {
      if(u == v) continue;
      if(g[u][v] == 0x3f3f3f3f) continue;
      if(lo <= lvl[v] && lvl[v] <= hi && dis[v] > dis[u] + g[u][v]) {
        dis[v] = dis[u] + g[u][v];
        if(!inq[v]) {
          inq[v] = 1;
          q.push(v);
        }
      } 
    }
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  memset(g, 0x3f, sizeof g);
  cin >> m >> n;

  FOR(i, 1, n) g[i][i] = 0;

  FOR(i, 1, n) {
    int p,l,x;
    cin >> p >> l >> x;
    lvl[i] = l;
    g[src][i] = min(g[src][i], p);
    FOR(j, 1, x) {
      int t, v;
      cin >> t >> v;
      g[t][i] = min(g[t][i], v);
    }
  }
  int ans = 10000;
  for(int hi = lvl[1]; hi - m <= lvl[1]; hi++) {
    int lo = hi - m;
    // printf("%d:%d\n", lo, hi);
    spfa(lo, hi);
    ans = min(ans, dis[1]);
  }
  cout << ans;
  return 0;
}
#endif