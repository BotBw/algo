#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 105;

int g[N][N];

int n, m;

int dis[N];
bool inq[N];

void spfa() {
  memset(dis, 0x3f, sizeof dis);
  queue<int> q;
  dis[1] = 0;
  inq[1] = true;
  q.push(1);

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    inq[u] = false;

    for(int v = 1; v <= n; v++) {
      if(u == v) continue;
      if(g[u][v] == 0x3f3f3f3f) continue;
      if(dis[v] > dis[u] + g[u][v]) {
        dis[v] = dis[u] + g[u][v];
        if(!inq[v]) {
          q.push(v);
          inq[v] = true;
        }
      }
    }
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;

  memset(g, 0x3f, sizeof g);
  
  FOR(i, 1, n) g[i][i] = 0;

  FOR(i, 1, m) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a][b] = g[b][a] = min(g[a][b], c);
  }

  spfa();

  int ans = 0;

  FOR(i, 2, n) {
    if(dis[i] == 0x3f3f3f3f) {
      cout << -1;
      return 0;
    }
    ans = max(ans, dis[i]);
  }
  cout << ans;
  return 0;
}
#endif