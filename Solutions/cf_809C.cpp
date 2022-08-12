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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    if(n & 1) {
      ll res = 0;
      for(int i = 2; i <= n; i += 2) {
        res += max(max(a[i-1] - a[i], a[i+1] - a[i]) + 1, 0ll);
      }
      cout << res << '\n';
    } else {
      vector<ll> pre(n + 1);
      vector<ll> post(n + 1);
      ll res = 0;
      for(int i = 2; i <= n - 1; i += 2) {
        res += max(max(a[i-1] - a[i], a[i+1] - a[i]) + 1, 0ll);
        pre[i + 1] = res;
      }
      res = 0;
      for(int i = n - 1; i >= 1; i -= 2) {
        res += max(max(a[i-1] - a[i], a[i+1] - a[i]) + 1, 0ll);
        post[i - 1] = res;
      }
      debug(pre, post);
      res = LLONG_INF;
      for(int i = 1; i <= n - 1; i += 2) {
        res = min(res, pre[i] + post[i + 1]);
      }
      cout << res << '\n';
    }
  }
  return 0;
}