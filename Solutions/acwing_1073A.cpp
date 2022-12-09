#include "bits/stdc++.h"

const int N = 10005;
int n;

struct {
  int v, w, next;
} e[N * 2];

int h[N], cnt;

void add(int a, int b, int c) {
  e[++cnt] = {b, c, h[a]};
  h[a] = cnt;
}

int up[N], down1[N], down2[N], ans;

void dfs_down(int u, int pre) {
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v, w = e[i].w;
    if(v == pre) continue;
    dfs_down(v, u);
    if(down1[v] + w >= down1[u]) {
      down2[u] = down1[u];
      down1[u] = down1[v] + w;
    } else if (down1[v] + w > down2[u]) {
      down2[u] = down1[v] + w;
    }
  }
}

void dfs_up(int u, int pre) {
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v, w = e[i].w;
    if(v == pre) continue;
    up[v] = up[u] + w;
    if(down1[v] + w == down1[u]) {
      up[v] = max(up[v], down2[u] + w);
    } else up[v] = max(up[v], down1[u] + w);
    dfs_up(v, u);
  }
  ans = min(ans, max(down1[u], up[u]));
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  FOR(i, 1, n-1) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
    add(b, a, c);
  }
  ans = INT_INF;
  up[1] = 0;
  dfs_down(1, 0);
  dfs_up(1, 0);
  cout << ans;
  return 0;
}