#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int max(int n,...) {va_list args;va_start(args, n);int ret = INT_MIN;FOR(i, 0, n-1)ret = max(ret, va_arg(args, int));va_end(args);return ret;}
int min(int n,...) {va_list args;va_start(args, n);int ret = INT_MAX;FOR(i, 0, n-1)ret = min(ret, va_arg(args, int));va_end(args);return ret;}

// #include "leet.h"

const int maxn = 1005;
const int maxm = 1e5 + 5;

int n, m;

struct edge {
  int u, v, w, next;
} e[maxm], er[maxm];

int head[maxn], headr[maxn];
int cnte, cnter;

void addE(edge e[], int &cnt, int head[], int u, int v, int m) {
  e[++cnt] = edge{u, v, m, head[u]};
  head[u] = cnt;
}
struct node {
  int i, dis;
  bool operator<(const node &b) const {
    return dis > b.dis;
  }
};
vector<int> dijkstra(edge *e, int *head) {
  vector<int> dis(n+1, 0x3f3f3f3f);
  vector<bool> vis(n+1, 0);
  priority_queue<node> q;
  dis[1] = 0;
  q.push({1, 0});
  while(!q.empty()) {
    auto x = q.top();
    q.pop();
    if(vis[x.i]) continue;
    vis[x.i] = 1;
    for(int i = head[x.i]; i != 0; i = e[i].next) {
      if(dis[e[i].v] > dis[x.i] + e[i].w) {
        dis[e[i].v] = dis[x.i] + e[i].w;
        q.push({e[i].v, dis[e[i].v]});
      }
    }
  }
  return dis;
}
#ifdef LEET
#else
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  FOR(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    addE(e, cnte, head, u, v, w);
    addE(er, cnter, headr, v, u, w);
  }
  auto dis = dijkstra(e, head);
  auto disr = dijkstra(er, headr);
  int ans = 0;
  FOR(i, 1, dis.size()-1) {
    ans += (dis[i] + disr[i]);
  }
  cout << ans;
  return 0;
}
#endif