#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 50005, M = 2e5 + 10, INF = 0x3f3f3f3f;

typedef pair<int,int> PII;

int n, m, ans = INF;
bool vr[6];
int r[6];

int dis[6][N];
bool vis[N];

int head[N], cnt;

struct edge {
  int v, w, nxt;
} e[M];

void add(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

void dijkstra(int *dis, int src) {
  fill_n(dis + 1, n, INF);
  memset(vis, 0, sizeof vis);

  dis[src] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, src});

  while(q.size()) {
    PII tmp = q.top();
    q.pop();
    int u = tmp.second;
    // printf("%d\n", u);
    if(vis[u]) continue;
    vis[u] = true;

    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

void dfs(int n, int cur, int val) {
  if(val >= ans) return;
  if(n == 6) {
    ans = val;
    return;
  }
  FOR(i, 0, 5) {
    if(vr[i]) continue;
    vr[i] = true;
    dfs(n + 1, i, dis[cur][r[i]] + val);
    vr[i] = false;
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  FOR(i, 1, 5) {
    cin >> r[i];
  }
  r[0] = 1;
  FOR(i, 1, m) {
    int x, y, t;
    cin >> x >> y >> t;
    add(x, y, t), add(y, x, t);
  }

  dijkstra(dis[0], 1);

  FOR(i, 1, 5) {
    dijkstra(dis[i], r[i]);
  }
  
  vr[0] = true;
  dfs(1, 0, 0);

  cout << ans;
  return 0;
}
#endif