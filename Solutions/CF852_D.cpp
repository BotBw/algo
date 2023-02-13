#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> p(n), q(n), invp(n + 1), invq(n + 1);
  FOR(i, 0, n-1) {
    cin >> p[i];
    invp[p[i]] = i;
  }
  FOR(i, 0, n-1) {
    cin >> q[i];
    invq[q[i]] = i;
  }
  int maxl = n + 1, minr = -1;
  ll res = 1;
  int lenl = min(invp[1], invq[1]);
  int lenr = min(n - 1 - invq[1], n - 1 - invp[1]);
  int lenmi = abs(invq[1] - invp[1]) - 1;
  res += 1LL * lenl * (lenl + 1) / 2;
  res += 1LL * lenr * (lenr + 1) / 2;
  res += 1LL * lenmi * (lenmi + 1) / 2;
  FOR(mex, 2, n) {
    maxl = min({maxl, invp[mex-1], invq[mex-1]});
    minr = max({minr, invp[mex-1], invq[mex-1]});

    int minl = 0, maxr = n - 1;
    if(invp[mex] < maxl) minl = max(minl, invp[mex] + 1);
    else maxr = min(maxr, invp[mex] - 1);

    if(invq[mex] < maxl) minl = max(minl, invq[mex] + 1);
    else maxr = min(maxr, invq[mex] - 1);

    debug(mex, minl, maxl, minr, maxr);
    if(minr <= maxr) res += 1LL * (maxl - minl + 1) * (maxr - minr + 1);
  }
  cout << res << endl;
  return 0;
}
