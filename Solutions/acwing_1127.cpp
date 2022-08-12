#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 805, INF = 0x3f3f3f3f;

struct edge {
  int v, w, next;
} e[1450*2 + 10];
int head[N], cnt;

void add(int a, int b, int c) {
  e[++cnt] = {b, c, head[a]};
  head[a] = cnt;
}

int farm[N];
int n, p, c;

int dis[N];
bool vis[N];

typedef pair<int, int> PII;

int dijkstra(int src) {
  memset(dis, 0x3f, sizeof dis);
  memset(vis, 0, sizeof vis);

  dis[src] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;

  q.push({0, src});

  while(q.size()) {
    PII tmp = q.top();
    q.pop();
    int u = tmp.second;

    if(vis[u]) continue;
    vis[u] = true;

   
    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if(dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        q.push({dis[v], v});
      }
    }
  }
  int ret = 0;
  FOR(i, 1, p) {
    if(farm[i] == 0) continue;
    if(dis[i] == INF) return INF;
    ret += (dis[i] * farm[i]);
  }
  return ret;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> p >> c;
  FOR(i, 1, n) {
    int id;
    cin >> id;
    farm[id]++;
  }

  FOR(i, 1, c) {
    int a, b, d;
    cin >> a >> b >> d;
    add(a, b, d), add(b, a, d);
  }
  int ans = 0x3f3f3f3f;
  FOR(i, 1, p) {
    ans = min(ans, dijkstra(i));
  }
  cout << ans;
  return 0;
}
#endif