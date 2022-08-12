#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)
// #ifdef DEBUG
// #include "debug.h"
// #endif
vector<int64_t> split(vector<int>& a, int m) {
  vector<int64_t> s;
  int pre = -1;
  int idx = 0;
  for (int i = 0; i < a.size();i++) {
    int64_t cnt;
    if (a[i] % m) {
      cnt = 1;
    }
    else {
      int64_t t = 1;
      while (a[i] % m == 0) {
        a[i] /= m;
        t *= m;
      }
      cnt = t;
    }

    if (a[i] == pre) {
      s.back() += cnt;
    }
    else {
      s.push_back(cnt);
      a[idx++] = a[i];
      pre = a[i];
    }
  }
  a.resize(s.size());
  return s;

}
void solve() {
  int n, m, k;

  cin >> n >> m;
  vector<int> a(n);
  FOR(i, 0, n-1) cin >> a[i];
  cin >> k;
  vector<int> b(k);
  FOR(i, 0, k-1) cin >> b[i];

  vector<int64_t> sa = split(a, m);
  vector<int64_t> sb = split(b, m);

  if (a.size() != b.size()) {
    cout << "No\n";
    return;
  }

  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i] || sa[i] != sb[i]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}