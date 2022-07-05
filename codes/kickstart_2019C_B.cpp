#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
typedef long long LL;
typedef pair<LL, LL> PLL;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

const int N = 305;
int g[N][N];
int f[N][N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int r, c, k;
    cin >> r >> c >> k;
    FOR(i, 1, r) {
      FOR(j, 1, c) {
        cin >> g[i][j];
      }
    }
    FOR(i, 1, r) {
      FOR(j, 1, c) {
        f[i][j] = 1;
        int min_s = g[i][j];
        int max_s = g[i][j];
        FOR(l, 2, j) {
          int j1 = j - l + 1;
          min_s = min(min_s, g[i][j1]);
          max_s = max(max_s, g[i][j1]);
          if(max_s - min_s <= k) f[i][j] = l;
          else break;
        }
        // cout << f[i][j] << ' ';
      }
      // cout << endl;
    }
    int res = 1;
    FOR(j, 1, c) {
      FOR(i1, 1, r) {
        int min_f = f[i1][j];
        res = max(res, min_f);
        FOR(l, 2, i1) {
          int i2 = i1 - l + 1;
          min_f = min(min_f, f[i2][j]);
          res = max(res, min_f * l);
        }
      }
    }
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}