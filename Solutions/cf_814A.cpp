#include "bits/stdc++.h"

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n, m;
    cin >> n >> m;
    int res = n + m - 2;
    if(res & 1) cout << "Burenka\n";
    else cout << "Tonya\n";
  }
  return 0;
}