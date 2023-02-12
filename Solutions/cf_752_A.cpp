#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n, m, a, b;
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    cin >> a >> b >> n >> m;
    ll cmp1 = m * a, cmp2 = (m + 1) * b;
    ll ans;
    if(cmp1 >= cmp2) {
      ans = n * b;
    } else {
      ll p = n / (m + 1), r = n % (m + 1);
      ans = p * m * a;
      ans += r * min(a, b);
    }
    cout << ans << endl;
  }
  return 0;
}