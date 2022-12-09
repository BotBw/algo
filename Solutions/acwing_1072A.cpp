#include "bits/stdc++.h"

const int N = 10005;
int n;

struct {
  int v, w, ne;
} e[N * 2];

int h[N], cnt;
int max1[N], max2[N], ans;

void add(int u, int v, int w) {
  e[++cnt] = {v, w, h[u]};
  h[u] = cnt;
}

void dfs(int u, int pre) {
  max1[u] = max2[u] = 0;
  for(int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v, w = e[i].w;
    if(v == pre) continue;
    dfs(v, u);
    if(max1[v] + w >= max1[u]) {
      max2[u] = max1[u];
      max1[u] = max1[v] + w;
    } else if (max1[v] + w > max2[u]) {
      max2[u] = max1[v] + w;
    }
  }
  ans = max({ans, max1[u] + max2[u]});
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
  ans = -INT_INF;
  dfs(1, -1);
  cout << ans;
  return 0;
}