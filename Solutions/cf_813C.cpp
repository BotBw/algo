#include "bits/stdc++.h"

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    set<int> hash, zeroed;
    int res = 0;
    zeroed.insert(0);
    FOR(i, 1, n-1) {
      if(zeroed.count(a[i])) a[i] = 0;
      else hash.insert(a[i]);
      if(zeroed.count(a[i + 1])) a[i + 1] = 0;
      if(a[i] > a[i + 1]) {
        for(auto p:hash) zeroed.insert(p);
        res += hash.size();
        hash.clear();
      }
    }
    cout << res << '\n';
    debug(zeroed);
  }
  return 0;
}