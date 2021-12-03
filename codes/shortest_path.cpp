#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

#define maxV 1000
#define maxE 10000

#ifdef maxV
#ifdef maxE
int head[maxV], cnt;

struct edge {
  int u, v, w, next;
} e[maxE];

void addE(int u, int v, int w) {
  e[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}
#endif
#endif

int V, E;

int f[maxV][maxV];

int dis[maxV];

struct node {
  int pos, dis;
  bool operator<(const node &b) const {
    return dis > b.dis; /* important */
  }
};

bool vis[maxV];
void dijkstra(int u) {
  memset(vis, 0, sizeof vis);
  memset(dis, 0x3f, sizeof dis);
  priority_queue<node> q;
  dis[u] = 0;
  q.push({u, 0});
  while(!q.empty()) {
    int u = q.top().pos;
    q.pop();
    if(vis[u]) continue; /* if condition is necessary here. if not, multiple node of 1 vertex will be pushed into heap and traversal all the edges of it */
    vis[u] = 1;
    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if(dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        if(!vis[v]) q.push({v, dis[v]}); /* if condition not necessary here, since the node will be discard after popping out from heap, but still optimization anyway */
      }
    }
  }
}

void floyd() {
  // initialization: memset(f, 0x3f, sizeof(f)); f[u][v] = min(f[u][v], w);
  // f[u][v][k] = min(f[u][v][k-1], f[u][k][k-1] = f[k][v][k-1]);
  FOR(k, 1, V) {
    FOR(i, 1, V) {
      FOR(j, 1, V) {
        f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
      }
    }
  }
}

bool bellman_ford(int s) {
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  bool flag = 0;
  FOR(i, 1, V) {
    FOR(j, 1, cnt) {
      int u = e[j].u, v = e[j].v, w = e[j].w;
      if(dis[u] > dis[v] + e[j].w) {
        dis[u] = dis[v] + e[j].w;
        flag = 1;
      }
    }
    if(!flag) break;
  }
  return flag;
}

bool inq[maxV];
int rel[maxV]; // counter of relaxing
bool spms(int s) {
  memset(dis, 0x3f, sizeof(dis));
  memset(inq, 0, sizeof(inq));
  queue<int> q;
  dis[s] = 0;
  q.push(s);
  inq[s] = 1;
  while(!q.empty()) {
    int u = q.front();
    inq[u] = 0;
    q.pop();
    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v, w = e[i].w;
      if(dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        rel[v]++;
        if(rel[v] >= V) return false;
        if(!inq[v]) q.push(v), inq[v] = 1;
      }
    }
  }
  return true;
}

int main() {
  cin >> V >> E;

  memset(f, 0x3f, sizeof(f));

  FOR(i, 1, E) {
    int u, v, w;
    cin >> u >> v >> w;
    addE(u, v, w);
    f[u][v] = min(f[u][v], w);
  }

}