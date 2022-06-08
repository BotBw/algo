#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 505, M = 5210;

int n, m, w;

struct edge {
  int v, w, next;
} e[M];

int head[N], cnt;

void add(int a, int b, int c) {
  e[++cnt] = {b, c, head[a]};
  head[a] = cnt;
}

int cntt[N], dis[N];

bool st[N];

bool spfa() {
  queue<int> q;

  memset(cntt, 0, sizeof cntt);
  memset(dis, 0x3f, sizeof dis);
  memset(st, 0, sizeof st);

  FOR(i, 1, n) {
    q.push(i);
    st[i] = true;
  }
  while(q.size()) {
    int u = q.front();
    q.pop();
    st[u] = false;

    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v, w = e[i].w;
      if(dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cntt[v] = cntt[u] + 1;
        if(cntt[v] >= n) return true;
        if(!st[v]) {
          q.push(v);
          st[v] = true;
        }
      }
    }
  }
  return false;
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> m >> w;
    cnt = 0;
    memset(head, 0, sizeof head);
    while(m--) {
      int a, b, c;
      cin >> a >> b >> c;
      add(a, b, c), add(b, a, c);
    }
    while(w--) {
      int a, b, c;
      cin >> a >> b >> c;
      add(a, b, -c);
    }
    if(spfa()) puts("YES");
    else puts("NO");
  }
  return 0;
}
#endif