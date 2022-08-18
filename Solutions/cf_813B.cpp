#include "bits/stdc++.h"

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    int res = 0;
    FOR(i, 1, k) {
      if(a[i] > k) res++;
    }
    cout << res << endl;
  }
  return 0;
}