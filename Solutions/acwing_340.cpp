#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// min(k+1 shortest path)
const int N = 1005, M = 20005, INF = 0x3f3f3f3f;

typedef pair<int,int> PII;
struct edge {
  int v, w, next;
} e[M];

int head[N], cnt;

void add(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int n, p, k;
int l = 0, r;

int dis[N];
bool vis[N];

void dijkstra(int val) {
  memset(dis, 0x3f, sizeof dis);
  memset(vis, 0, sizeof vis);
  priority_queue<PII, vector<PII>, greater<PII>> q;
  dis[1] = 0;
  q.push({0, 1});

  while(q.size()) {
    int u = q.top().second;
    q.pop();
    if(vis[u]) continue;
    vis[u] = true;

    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v, w = e[i].w;
      int c = 1;
      if(w <= val) c = 0;
      if(dis[v] > dis[u] + c) {
        dis[v] = dis[u] + c;
        q.push({dis[v], v});
      }
    }
  }
}

bool check(int mi) {
  dijkstra(mi);
  // cout << mi << ":\n";
  // FOR(i, 1, n) {
  //   cout << dis[i] << "   ";
  // }
  return dis[n] <= k;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  scanf("%d%d%d", &n, &p, &k);

  FOR(i, 1, p) {
    int a, b, ll;
    cin >> a >> b >> ll;
    r = max(r, ll);
    add(a, b, ll);
    add(b, a, ll);
  }
  r++;
  while(l < r) {
    // printf("%d:%d\n", l, r);
    int mi = (l + r)/2;
    if(check(mi)) {
      r = mi;
    } else {
      l = mi + 1;
    }
  }

  if(dis[n] == INF) cout << -1;
  else cout << l;

  return 0;
}
#endif