#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  string p, s;
  cin >> n >> p >> m >> s;
  p.insert(p.begin(), 0);
  s.insert(s.begin(), 0);
  vector<int> f(m + 1);
  int j = 0;
  FOR(i, 2, n) {
    while(j && p[i] != p[j + 1]) j = f[j];
    if(p[i] == p[j + 1]) j++;
    f[i] = j;
  }

  j = 0;
  FOR(i, 1, m) {
    while(j && s[i] != p[j + 1]) j = f[j];
    if(s[i] == p[j + 1]) j++;
    if(j == n) {
      cout << i - n << ' ';
      j = f[j];
    }
  }
  return 0;
}