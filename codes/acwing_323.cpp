#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#endif

const int N = 1505;

int n;

struct edge {
  int v, next;
} e[N * 2];

int h[N], cnt;

int f[N][2];

void add(int a, int b) {
  e[++cnt] = {b, h[a]};
  h[a] = cnt;
}

void dfs(int u, int fa) {
  f[u][0] = 0;
  f[u][1] = 1;
  for (int i = h[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
    f[u][0] += f[v][1];
    f[u][1] += min(f[v][0], f[v][1]);
  }
}

int main() {
  while (~scanf("%d", &n)) {
    memset(h, 0, sizeof h);
    cnt = 0;
    for (int i = 0; i < n; i++) {
      int a, b, siz;
      scanf("%d:(%d) ", &a, &siz);
      a++;
      while (siz--) {
        scanf("%d", &b);
        b++;
        add(a, b);
        add(b, a);
      }
    }
    dfs(1, -1);
    printf("%d\n", min(f[1][0], f[1][1]));
  }

  return 0;
}
