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
    int n;
    cin >> n;
    int xi_mn, xi_mx, yi_mn, yi_mx;
    xi_mn = yi_mn = INT_INF;
    xi_mx = yi_mx = -INT_INF;
    FOR(i, 1, n) {
      int xi, yi;
      cin >> xi >> yi;
      if(xi == 0) {
        yi_mn = min(yi_mn, yi);
        yi_mx = max(yi_mx, yi);
      } else {
        xi_mn = min(xi_mn, xi);
        xi_mx = max(xi_mx, xi);
      }
    }
    int res = 0;
    if(xi_mx != -INT_INF) res += 2*(max(0, xi_mx) - min(0, xi_mn));
    if(yi_mx != -INT_INF) res += 2*(max(0, yi_mx) - min(0, yi_mn));
    cout << res << endl;
  }
  return 0;
}