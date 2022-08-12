#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 1e5+5, M = 4e5 + 5, MOD = 100003;


typedef pair<int, int> PII;

int n, m;

struct edge  {
  int v, next;
} e[M];

int head[N], cnt;

void add(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}

int dis[N], cntt[N];
bool st[N];

void dijkstra() {
  memset(dis, 0x3f, sizeof dis);
  dis[1] = 0;
  cntt[1] = 1;
  priority_queue<PII, vector<PII>, greater<PII>> pq;
  pq.push({0, 1});

  while(pq.size()) {
    int u = pq.top().second;
    pq.pop();

    if(st[u]) continue;
    st[u] = true;

    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if(dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        cntt[v] = cntt[u];
        pq.push({dis[v], v});
      } else if(dis[v] == dis[u] + 1) {
        cntt[v] += cntt[u];
        cntt[v] %= MOD;
      }
    }
  }
  
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dijkstra();
  FOR(i, 1, n) {
    printf("%d\n", cntt[i]);
  }
  return 0;
}
#endif