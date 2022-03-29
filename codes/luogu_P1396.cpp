#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

int n, m, s, t;
const int maxn = 1e4+5;
const int maxm = 2e4+5;

struct edge {
  int x, dis;
  bool operator>(const edge &b) const {
    return dis > b.dis;
  }
  bool operator==(const edge &b) const {
    return x == b.x;
  }
} e[maxm];

int dis[maxn];
bool vis[maxn];

struct node {
  int x, dis;
    bool operator<(const node &b) const {
    return dis > b.dis;
  }
};

vector<vector<edge>> edgesOf;

void prim() {
  memset(dis, 0x3f, sizeof(dis));
  priority_queue<node> q;
  dis[s] = 0;
  q.push({s, 0});

  while(!q.empty()) {
    auto least = q.top();
    q.pop();
    if(vis[least.x]) continue;
    vis[least.x] = true;
    for(auto e:edgesOf[least.x]) {
      int neck = max(dis[least.x], e.dis);
      if(dis[e.x] > neck) {
        dis[e.x] = neck;
        q.push({e.x, neck});
      }
    }
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m >> s >> t;
  edgesOf.reserve(n*2+1);
  FOR(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    edgesOf[u].push_back({v, w});
    edgesOf[v].push_back({u, w});
  }
  FOR(i, 1, n) {
    sort(edgesOf[i].begin(), edgesOf[i].end(), greater<edge>());
    edgesOf[i].resize(distance(edgesOf[i].begin(), unique(edgesOf[i].begin(), edgesOf[i].end())));
  }
  prim();
  cout << dis[t];
  return 0;
}
#endif