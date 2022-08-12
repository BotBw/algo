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
  FOR(t, 1 ,tt) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    FOR(i, 0, n-1) cin >> a[i];
    map<ll, ll> cnt;
    FOR(i, 0, n-1) cnt[a[i]]++;
    ll max_cnt = 1;
    for(auto &p:cnt) max_cnt = max(max_cnt, p.second);
    if(max_cnt == n) {
      cout << 0 << '\n';
      continue;
    }
    ll k = max_cnt;
    ll res = 0;
    while(k < n) {
      k *= 2;
      res++;
    }
    res += n - max_cnt;
    cout << res << '\n';
  }
  return 0;
}