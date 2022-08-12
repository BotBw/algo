#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n;
    cin >> n;
    vector<int> p(n + 2);
    FOR(i, 1, n) cin >> p[i];
    vector<vector<int>> pre(n + 1, vector<int>(n + 1));
    vector<vector<int>> post(n + 2, vector<int>(n + 2));
    p[0] = n + 1;
    p[n + 1] = n + 1;
    FOR(i, 1, n) {
      FOR(j, 1, n) {
        pre[i][j] = pre[i-1][j] + (p[i - 1] < j);
        // cout << pre[i][j] << " \n"[j == n];
      }
    }
    
    _FOR(i, n, 1) {
      FOR(j, 1, n) {
        post[i][j] = post[i + 1][j] + (p[i + 1] < j);
      }
    }
    LL res = 0;
    FOR(b, 1, n) {
      FOR(c, b + 1, n) {
        res += pre[b][p[c]] * post[c][p[b]];
      }
    }
    cout << res << '\n';
  }
  return 0;
}