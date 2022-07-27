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

    vector<int> h(n);
    for(auto &v:h) cin >> v;
    debug(h);
    int l = 0, r = 0;
    for(auto v:h) r = max(r, v);
    debug(l, r);
    auto check = [&](int mi) {
      auto a = h;
      _FOR(i, n-1, 2) {
        if(a[i] < mi) return false;
        int d = min(h[i], a[i] - mi) / 3;
        a[i-1] += d;
        a[i-2] += d*2;
      }
      return a[0] >= mi && a[1] >= mi;
    };
    while(l < r) {
      int mi = (l + r + 1) / 2;
      if(check(mi)) l = mi;
      else r = mi - 1;
    }
    debug(h);
    cout << l << endl;
  }
  return 0;
}