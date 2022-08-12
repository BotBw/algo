#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 1005, M = 20000005;
// const int N = 1005, M = 1000;


typedef pair<int, int> PII;

struct edge {
  int v, w, next;
} e[M];

int head[N*N], cnt;

void add(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int n, p, k;

int dis[N*N];
bool vis[N*N];

void dijkstra() {
  memset(dis, 0x3f, sizeof dis);

  priority_queue<PII, vector<PII>, greater<PII>> pq;
  dis[1] = 0;
  pq.push({0, 1});

  while(pq.size()) {
    int u = pq.top().second;
    pq.pop();

    // if(u == 0) break;

    if(vis[u]) continue;
    vis[u] = true;


    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v, w = max(e[i].w, dis[u]);
      if(dis[v] > w) {
        dis[v] = w;
        pq.push({dis[v], v});
      }
    }
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  scanf("%d%d%d", &n, &p, &k);

  FOR(i, 1, p) {
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    add(a, b, l), add(b, a, l);
    FOR(j, 1, k) {
      add(a + (j-1)*n, b + j*n, 0);
      add(b + (j-1)*n, a + j*n, 0);
      add(a + j*n, b + j*n, l);
      add(b + j*n, a + j*n, l);
    }
  }

  FOR(i, 1, k+1) {
    add(i*n, 0, 0);
  }

  dijkstra();

  if(dis[0] == 0x3f3f3f3f) puts("-1");
  else printf("%d\n", dis[0]);
  return 0;
}
#endif