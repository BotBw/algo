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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), d(n + 1);
    FOR(i, 1, n) cin >> a[i];
    vector<pii> e(m + 1);
    FOR(i, 1, m) {
      int u, v;
      cin >> u >> v;
      e[i] = {u, v};
      d[u]++;
      d[v]++;
    }
    if(!(m & 1)) {
      cout << 0 << '\n';
      continue;
    }
    int res = INT_INF;
    FOR(i, 1, n) {
      if(d[i] & 1) res = min(res, a[i]);
    }
    FOR(i, 1, m) {
      if(!(d[e[i].first] & 1) && !(d[e[i].second] & 1)) {
        res = min(res, a[e[i].first] + a[e[i].second]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}