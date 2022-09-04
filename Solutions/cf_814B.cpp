#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n, k;
    cin >> n >> k;
    if(k % 4 == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if(k % 4 == 2) {
      for (int i = 2; i <= n; i += 2) {
        if(i % 4 == 2) {
          cout << i << ' ' << i - 1 << endl;
        } else {
          cout << i - 1 << ' ' << i << endl;
        }
      }
    } else {
      for (int i = 1; i <= n; i += 2) {
        cout << i << ' ' << i + 1 << endl;
      }
    }
  }
  return 0;
}