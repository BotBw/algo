#include "bits/stdc++.h"

const int N = 105, Q = 105;

int n, q;

struct {
  int v, w, ne;
} e[N];

int h[N], cnt;

void add(int u, int v, int w) {
  e[++cnt] = {v, w, h[u]};
  h[u] = cnt;
}

int f[Q][N];

void dfs(int u, int pre) {
  
  for(int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if(v == pre) continue;
    dfs(v, u);
  }

  for(int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v, w = e[i].w;
    if(v == pre) continue;
    for(int j = q; j >= 0; j--) {
      for(int k = 1; k <= j; k++) {
        f[j][u] = max({f[j][u], f[j - k][u] + f[k-1][v] + w});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  FOR(i, 1, n-1) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w);
  }
  dfs(1, 0);
  cout << f[q][1];
  return 0;
}