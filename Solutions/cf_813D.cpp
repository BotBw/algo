#include "bits/stdc++.h"

int n, k;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    cin >> n >> k;
    vector<int> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    int l = 0, r = 1e9;
    auto check = [&](int x) {
      vector<int> aa = a;
      int kk = k;
      FOR(i, 1, n) {
        if(aa[i] * 2 < x) {
          kk--;
          aa[i] = 1e9;
          if(kk < 0) return false;
        }
      }
      if(kk == 0) {
        FOR(i, 1, n-1) {
          if(min(aa[i], aa[i+1]) >= x) return true;
        }
      } else if(kk == 1) {
        FOR(i, 1, n) {
          if(aa[i] >= x) return true;
        }
      } else if(kk >= 2) return true;
      return false;
    };
    // cout << check(9) << endl;
    while(l < r) {
      int mi = (l + r + 1) >> 1;
      if(check(mi)) l = mi;
      else r = mi - 1;
    }
    cout << l << '\n';
  }
  return 0;
}