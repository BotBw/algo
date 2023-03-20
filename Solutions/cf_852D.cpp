#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> p(n + 1), q(n + 1);
  vector<int> invp(n + 1), invq(n + 1);
  FOR(i, 1, n) {
    cin >> p[i];
    invp[p[i]] = i;
  }
  FOR(i, 1, n) {
    cin >> q[i];
    invq[q[i]] = i;
  }
  ll ans = 0;
  // 1
  int lenl = min(invp[1], invq[1]) - 1;
  int lenr = n - max(invp[1], invq[1]);
  int lenm = abs(invp[1] - invq[1]) - 1;
  ans += 1ll * lenl * (lenl + 1) / 2;
  ans += 1ll * lenr * (lenr + 1) / 2;
  ans += 1ll * lenm * (lenm + 1) / 2;
  debug(ans);
  int lmax = n, rmin = 1;
  // [2, n]
  FOR(mex, 2, n) {
    lmax = min(lmax, invp[mex - 1]);
    rmin = max(rmin, invp[mex - 1]);
    lmax = min(lmax, invq[mex - 1]);
    rmin = max(rmin, invq[mex - 1]);
    debug(mex, lmax, rmin);
    int _p = invp[mex];
    int _q = invq[mex];
    int lmin = 1, rmax = n;
    if(_p < lmax) {
      lmin = max(_p + 1, lmin);
    } else {
      rmax = min(_p - 1, rmax);
    }

    if(_q < lmax) {
      lmin = max(_q + 1, lmin);
    } else {
      rmax = min(_q - 1, rmax);
    }
    if(lmin <= lmax && rmin <= rmax) {
      ans += 1ll * (lmax - lmin + 1) * (rmax - rmin + 1);
    }
  }
  // n + 1
  ans++;
  cout << ans;
  return 0;
}