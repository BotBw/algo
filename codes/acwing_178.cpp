#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> piii;

vector<int> h, rh;
struct edge {
  int v, w, next;
};
vector<edge> e;
vector<int> dis, cnt;
vector<bool> vis;
int s, t, k;

struct node {
  int u, d;
  bool operator<(const node &b) const {
    return d + dis[u] > b.d + dis[b.u];
  }
};

void add(vector<int> &hh, int a, int b, int l) {
  e.push_back({b, l, hh[a]});
  hh[a] = e.size() - 1;
}

void dijkstra(int st) {
  dis[st] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, st});
  while(q.size()) {
    auto cur = q.top();
    int u = cur.second;
    q.pop();
    if(vis[u]) continue;
    vis[u] = true;
    for(int i = rh[u]; ~i; i = e[i].next) {
      int v = e[i].v;
      if(dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        q.push({dis[v], v});
      }
    }
  }
}

void astar(int st) {
  priority_queue<node> q;
  q.push({st, 0});
  while(q.size()) {
    auto cur = q.top(); q.pop();
    int u = cur.u;
    // debug(u);
    cnt[u]++;
    if(u == t && cnt[u] == k) {
      cout << cur.d;
      return;
    }
    for(int i = h[u]; ~i; i = e[i].next) {
      int v = e[i].v, w = e[i].w;
      if(cnt[v] <= k) q.push({v, cur.d + w});
    }
  }
  cout << -1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  h = rh = vector<int>(n + 1, -1);
  dis = vector<int>(n + 1, INT_INF);
  vis = vector<bool>(n + 1);
  cnt = vector<int>(n + 1);
  FOR(i, 1, m) {
    int a, b, l;
    cin >> a >> b >> l;
    add(h, a, b, l);
    add(rh, b, a, l);
  }
  cin >> s >> t >> k;
  if(s == t) k++;
  dijkstra(t);
  astar(s);
  return 0;
}