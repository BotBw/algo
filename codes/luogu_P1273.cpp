#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n, m;
int h[N], ecnt;
int f[N][N];
int sz[N];

struct edge {
  int v, w, next;
} e[N];

void add(int a, int b, int w) {
  e[++ecnt] = {b, w, h[a]};
  h[a] = ecnt;
}

void dfss(int u) {
  if(!h[u]) {
    sz[u] = 1;
    return;
  }
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v;
    dfss(v);
    sz[u] += sz[v];
  }
}

void dfs(int u) {
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v, w = e[i].w;
    dfs(v);
    for(int j = sz[u]; j >= 0; j--) {
      for(int k = 0; k <= j; k++) {
        f[u][j] = max(f[u][j], f[v][k] + f[u][j - k] + w);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  memset(f, -0x3f, sizeof f);
  for (int i = 1; i <= n - m; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; j++) {
      int a, c;
      scanf("%d%d", &a, &c);
      add(i, a, -c);
    }
  }
  for (int i = n - m + 1; i <= n; i++) {
    int c;
    scanf("%d", &c);
    f[i][1] = c;
  }
  for(int i = 1; i <= n; i++) f[i][0] = 0;
  dfss(1);
  dfs(1);
  int i = n - 1;
  for (; i > 0; i--) {
    if(f[1][i] >= 0) break;
  }
  printf("%d", i);
  return 0;
}