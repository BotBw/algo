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
  FOR(_, 1, tt) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    if(n == 1) {
      cout << "0\n";
      continue;
    }
    int mn = a[1], mx = a[1];
    int res = 0;
    for(int r = 1; r <= n; r++) {
      mx = max(mx, a[r]);
      mn = min(mn, a[r]);
      if(mx - mn > x * 2) {
        res++;
        mx = mn = a[r];
      }
    }
    cout << res << endl;
  }
  return 0;
}