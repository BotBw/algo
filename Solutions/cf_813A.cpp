#include "bits/stdc++.h"

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n;
    cin >> n;
    vector<int> res(n + 1);
    int i = n;
    for(; i - 2 >= 0; i -= 2) {
      res[i] = i - 1;
      res[i-1] = i;
    } 
    if(i == 1) res[1] = 1;
    FOR(i, 1, n) cout << res[i] << " \n"[i == n];
  }
  return 0;
}