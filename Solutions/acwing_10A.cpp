#include "bits/stdc++.h"

struct edge {
  int v, next;
};

int N, V;
vector<int> h;
vector<edge> es;
vector<int> v, w;
vector<vector<int>> f;

void add(int u, int vv) {
  es.push_back({vv, h[u]});
  h[u] = es.size() - 1;
}

void dfs(int u) {
  FOR(i, v[u], V) f[u][i] = w[u];
  for(int i = h[u]; i != -1; i = es[i].next) {
    int vv = es[i].v;
    dfs(vv);
    _FOR(j, V, v[u]) {
      FOR(k, 0, j - v[u]) {
        f[u][j] = max(f[u][j], f[vv][k] + f[u][j - k]);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> V;
  v = w = vector<int>(N + 1);
  h = vector<int>(N + 1, -1);
  f = vector<vector<int>>(N + 1, vector<int>(V + 1));
  int rt = 0;
  FOR(i, 1, N) {
    int p;
    cin >> v[i] >> w[i] >> p;
    if(p != -1) {
      add(p, i);
    } else {
      rt = i;
    }
  }
  dfs(rt);
  cout << f[rt][V];
  return 0;
}