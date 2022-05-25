#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 2505, M = 6200*2 + 10, INF = 0x3f3f3f3f;
int T, C, ts, te;
typedef pair<int,int> PII;
struct edge {
  int v, w, next;
} e[M];

int head[N], cnt;

void addE(int a, int b, int c) {
  e[++cnt] = {b, c, head[a]};
  head[a] = cnt;
}
int dis[N];
bool vis[N];
void djkstra() {
  memset(dis, INF, sizeof dis);
  dis[ts] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, ts});

  while(!q.empty()) {
    PII tmp = q.top();
    q.pop();

    int u = tmp.second;
    if(u == te) break;
    for(int i = head[u]; i ; i = e[i].next) {
      int v = e[i].v;
      if(dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        q.push({dis[v], v});
      }
    }
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> T >> C >> ts >> te;
  FOR(i, 1, C) {
    int a, b, c;
    cin >> a >> b >> c;
    addE(a, b, c);
    addE(b, a, c);
  }

  djkstra();

  cout << dis[te];
  return 0;
}
#endif