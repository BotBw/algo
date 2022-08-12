#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
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
    int n;
    cin >> n;
    vector<int> h(n + 1), dp1(n + 1), dp2(n + 1);
    FOR(i, 1, n) cin >> h[i];
    FOR(i, 1, n) {
      dp1[i] = 1;
      FOR(j, 1, i-1) {
        if(h[j] < h[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
      }
    }
    _FOR(i, n, 1) {
      dp2[i] = 1;
      _FOR(j, n, i+1) {
        if(h[j] < h[i]) dp2[i] = max(dp2[i], dp2[j] + 1);
      }
    }
    int ans = 0;
    FOR(i, 1, n) {
      ans = max(ans, max(dp1[i], dp2[i]));
    }
    cout << ans << endl;
  }
  return 0;
}