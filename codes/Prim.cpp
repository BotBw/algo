#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxn = 5e3+5, maxm = 2e5+5, INF = 0x3f3f3f3f;

int n, m, S;
int head[maxn], cnt, ans, connected;
bool vis[maxn];
int dis[maxn];


struct edge {
  int v, w, nxt;
} e[maxm*2];

struct node {
  int id, dis;
  bool operator<(const node &b) const {
    return dis > b.dis;
  }
};

void addE(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

void prim() {
  srand(time(0));
  S = (rand()%n) + 1;
  for(int i = 1; i <= n; i++) vis[i] = 0, dis[i] = INF;
  priority_queue<node> q;
  dis[S] = 0;
  q.push({S, 0});
  ans = 0;

  while(!q.empty()) {
    auto cur = q.top(); q.pop();
    if(vis[cur.id]) continue;
    vis[cur.id] = 1;
    ans += cur.dis;
    connected++;
    for(int i = head[cur.id]; i ; i = e[i].nxt) {
      if(dis[e[i].v] > e[i].w) {
        dis[e[i].v] = e[i].w;
        if(!vis[e[i].v]) {
          q.push({e[i].v, dis[e[i].v]});
        }
      }
    }
  }
  
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    addE(u, v, w);
    addE(v, u, w);
  }
  prim();
  if(connected == n)
    cout << ans;
  else 
    cout << "orz";
  return 0;
}