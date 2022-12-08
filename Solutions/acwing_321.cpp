#include "bits/stdc++.h"

int f[16][9][9][9][9];
int a[9][9], pre[9][9];

inline int rec(int x1, int y1, int x2, int y2) {
  return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
}

int dfs(int k, int x1, int y1, int x2, int y2) {
  debug(k, x1, y1, x2, y2);
  if(f[k][x1][y1][x2][y2] != INT_INF) return f[k][x1][y1][x2][y2];
  if(k == 0) return f[k][x1][y1][x2][y2] = rec(x1, y1, x2, y2) * rec(x1, y1, x2, y2);
  if(x1 == x2 && y1 == y2) return f[k][x1][y1][x2][y2] = INT_INF - 1;
  // vertical

  int minf = INT_INF - 1;
  FOR(i, x1, x2 - 1) {
    minf = min({minf, rec(x1, y1, i, y2)*rec(x1, y1, i, y2) + dfs(k-1, i + 1, y1, x2, y2)});
    minf = min({minf, rec(i + 1, y1, x2, y2)*rec(i + 1, y1, x2, y2) + dfs(k-1, x1, y1, i, y2)});
  }
  // horizontal
  FOR(j, y1, y2 - 1) {
    minf = min({minf, rec(x1, y1, x2, j)*rec(x1, y1, x2, j) + dfs(k-1, x1, j + 1, x2, y2)});
    minf = min({minf, rec(x1, j + 1, x2, y2)*rec(x1, j + 1, x2, y2) + dfs(k-1, x1, y1, x2, j)});
  }

  return f[k][x1][y1][x2][y2] = minf;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  memset(f, 0x3f, sizeof f);
  int n;
  cin >> n;
  
  FOR(i, 1, 8)
    FOR(j, 1, 8)
      cin >> a[i][j];

  double x_sum = 0;

  FOR(i, 1, 8)
    FOR(j, 1, 8) {
      x_sum += a[i][j];
    }
  
  double x_bar = x_sum / n;

  FOR(i, 1, 8) {
    FOR(j, 1, 8) {
      pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
    }
  }

  // minimize sigma x_i ^ 2
  int sqrt_sum = dfs(n-1, 1, 1, 8, 8);

  double ans = sqrt((sqrt_sum - 2 * x_sum * x_bar + n*x_bar*x_bar)/n);
  cout << setprecision(3) << fixed << ans << endl;
  return 0;
}