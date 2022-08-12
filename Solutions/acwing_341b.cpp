#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = (1e5 + 5) * 3, M = (500000 * 3 + 3 * N + 10)*2;
// const int N = 100, M = (50 * 3 + 3 * N + 10)*2;

int n, m;

int head[N], cnt;

struct edge {
  int v, w, next;
} e[M];

void add(int u, int v, int w) {
  e[++cnt] = {v, w ,head[u]};
  head[u] = cnt;
}

int dis[N];
bool st[N];

void spfa() {
  memset(dis, -0x3f, sizeof dis);
  queue<int> q;
  dis[1] = 0;
  st[1] = true;
  q.push(1);

  while(q.size()) {
    int u = q.front();
    // printf("%d:%d\n", u, dis[u]);
    q.pop();
    st[u] = false;

    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v; int w = e[i].w;
      if(dis[v] < dis[u] + w) {
        dis[v] = dis[u] + w;
        if(!st[v]) {
          q.push(v);
          st[v] = true;
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
  FOR(i, 1, n) {
    int val;
    scanf("%d", &val);
    add(i, i + n, -val);
    add(i + n, i + 2*n, val);
  }
  FOR(i, 1, m) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    FOR(k, 0, 2) {
      add(x + k*n, y + k*n, 0);
    }
    if(z == 2) {
      FOR(k, 0, 2) {
        add(y + k*n, x + k*n, 0);
      }
    }
  }
  add(n, 0, 0);
  add(n*3, 0, 0);
  spfa();
  printf("%d", dis[0]);
  return 0;
}
#endif