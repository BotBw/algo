#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
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
    vector<int> a(n + 1), ans(n + 1);
    FOR(i, 1, n) cin >> a[i];
    vector<pii> b;
    FOR(i, 1, n) b.push_back({a[i], i});
    sort(b.begin(), b.end(), greater<pii>());
    unsigned long long res = 0;
    int i = 1;
    debug(b);
    for(; i < (int) b.size(); i += 2) {
      int d = (i + 1) / 2;
      res += (ll)b[i].first * d;
      res += (ll)b[i-1].first * d;
      ans[b[i].second] = d;
      ans[b[i-1].second] = -d;
    }
    if(i == (int)b.size()) {
      i -= 1;
      int d = (b.size() + 1)/2;
      res += (ll)b[i].first * d;
      ans[b[i].second] = d;
    }
    res *= 2;
    cout << res << endl;
    for(auto e:ans) cout << e << ' ';
    cout << endl;
  }
  return 0;
}