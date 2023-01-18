#include "bits/stdc++.h"
#define int long long

const int N = 1505;

int h[N], ecnt, n, cost[N];

struct edge {
  int u, v, ne;
} e[N * 2];

void add(int u, int v) {
  e[++ecnt] = {u, v, h[u]};
  h[u] = ecnt;
}

int f[N][3]; // no placement (watched by pa)
            // no placement (watched by ch)
            // placement

void dfs(int u, int fa) {
  f[u][0] = 0;
  f[u][1] = 0;
  f[u][2] = cost[u];
  bool hasYes = false;
  int minDiff = INT_INF;
  for(int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if(v == fa) continue;
    dfs(v, u);
    f[u][0] += min(f[v][1], f[v][2]);
    f[u][2] += min({f[v][0], f[v][1], f[v][2]});
    // at least one f[v][2];
    int yes = f[v][2], no = f[v][1];
    if(yes <= no) {
      f[u][1] += yes;
      hasYes = true;
    } else {
      minDiff = min(minDiff, yes - no);
      f[u][1] += no;
    }
  }
  if(!hasYes) {
    f[u][1] += minDiff;
  }
}

signed main() {
  // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  FOR(_, 1, n) {
    int i, k, m;
    cin >> i >> k >> m;
    cost[i] = k;
    FOR(__, 1, m) {
      int r;
      cin >> r;
      add(i, r);
      add(r, i);
    }
  }
  dfs(1, -1);
  cout << min(f[1][1], f[1][2]) << endl;
  return 0;
}