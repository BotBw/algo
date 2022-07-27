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

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    int n;
    cin >> n;
    vector<int> a(n+1), pos(n);
    FOR(i, 1, n) cin >> a[i];
    if(n <= 2) {
      cout << 1 << endl;
      continue;
    }
    FOR(i, 1, n) {
      pos[a[i]] = i;
    }
    int l = min(pos[0], pos[1]);
    int r = max(pos[0], pos[1]);
    ll res = 1;
    const ll MOD = 1e9 + 7;
    int cnt = 0;
    FOR(i, 2, n-1) {
      debug(l, r);
      if(l <= pos[i] && pos[i] <= r) {
        res *= r - l - 1 - cnt;
        res %= MOD;
        cnt++;
      } else {
        if(pos[i] < l) l = pos[i];
        if(pos[i] > r) r = pos[i];
        cnt += 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}