#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

int R, C;
const int maxr = 105;

int h[maxr][maxr];
int f[maxr][maxr];

const int dir[5] = {1, 0, -1, 0, 1};

int dfs(int i, int j) {
  if(f[i][j]) return f[i][j];
  int x, y;
  int maxF = 0;
  FOR(k, 0, 3) {
    x = i+dir[k];
    y = j+dir[k+1];
    if(h[x][y] < h[i][j]) {
      maxF = max(maxF, dfs(x, y));
    }
  }
  f[i][j] = maxF+1;
  return f[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C;
  FOR(i, 1, R) {
    FOR(j, 1, C) {
      cin >> h[i][j];
    }
  }
  FOR(i, 1, R) h[i][0] = h[i][C+1] = INT_MAX;
  FOR(j, 1, C) h[0][j] = h[R+1][j] = INT_MAX;
#ifdef DEBUG
  FOR(i, 0, R+1) {
    FOR(j, 0, C+1) {
      cout << h[i][j] << ' ';
    }
    cout << '\n';
  }
#endif
  int ans = 0;
  FOR(i, 1, R) {
    FOR(j, 1, C) {
      ans = max(ans, dfs(i, j));
    }
  }
  cout << ans;
  return 0;
}