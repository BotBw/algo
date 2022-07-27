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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    int res = INT_INF;
    FOR(minVal, a[1]/k, a[1]) {
      // debug(minVal);
      int tmp = 0;
      FOR(i, 1, n) {
        int pi;
        if(minVal == 0) pi = k;
        else pi = min(k, a[i]/minVal);
        // debug(a[i], pi, a[i]/pi);
        int maxVal = a[i]/pi;
        tmp = max(tmp, maxVal - minVal);
      }
      // debug(tmp);
      res = min(res, tmp);
    }
    cout << res << endl;
  }
  return 0;
}