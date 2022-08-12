#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 1005, M = N*N;

bool g[N][N];

struct edge {
  int v, next;
} e[M];

int head[N], cnt;
int line[N];
int n, m;

void add(int a, int b) {
  e[++cnt] = {b ,head[a]};
  head[a] = cnt;
}
bool in[N];

int dis[N];
bool st[N];

void spfa() {
  queue<int> q;

  FOR(i ,1, n) {
    if(!in[i]) {
      dis[i] = 1;
      q.push(i);
      st[i] = true;
    }
  }

  while(q.size()) {
    int u = q.front();
    // printf("%d:%d\n", u, dis[u]);
    q.pop();
    st[u] = false;

    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if(dis[v] < dis[u] + 1) {
        dis[v] = dis[u] + 1;
        // printf("%d->%d: %d\n", u, v, dis[v]);

        if(!st[v]) {
          st[v] = true;
          q.push(v);
        }
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

    int s;
    unordered_set<int> q;

    scanf("%d", &s);

    FOR(j, 1, s) {
      scanf("%d", &line[j]);
      q.insert(line[j]);
    }

    FOR(j ,line[1] ,line[s]) {
      if(!q.count(j)) {
        FOR(k, 1, s) {
          if(!g[j][line[k]]) {
            g[j][line[k]] = true;
            add(j, line[k]);
            // printf("%d->%d\n", j, line[k]);
            in[line[k]] = true;
          }
        }
      }
    }

  }

  spfa();

  int ans = 1;
  FOR(i, 1, n) {
    // printf("%d ", dis[i]);
    ans = max(ans, dis[i]);
  }
  printf("%d", ans);
  return 0;
}
#endif