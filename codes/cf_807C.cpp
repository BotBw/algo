#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n,c,q;
string s;
vector<vector<ll>> cp;

void solve() {
  cin >> n >> c >> q;
  cin >> s;
  ll len = n;
  cp.clear();
  FOR(i, 1, c) {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    len += (r - l + 1);
    cp.push_back({len, l, r});
  }
  // debug(cp);
  FOR(i, 1, q) {
    ll k;
    cin >> k;
    k--;
    _FOR(j, c - 1, 0) {
      ll lenn = cp[j][0], l = cp[j][1], r = cp[j][2];
      ll cp_len = r - l + 1;
      // debug(k, l, r, lenn, cp_len);
      if(k >= lenn - cp_len) k = k - lenn + cp_len + l;
    }
    cout << s[k] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    solve();
  }
  return 0;
}