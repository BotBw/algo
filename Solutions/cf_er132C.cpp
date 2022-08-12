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
    int n, x;
    cin >> n >> x;
    vector<ll> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> pre(a);
    FOR(i, 1, n) pre[i] = pre[i-1] + pre[i];
    ll res = 0;
    int i = upper_bound(pre.begin(), pre.end(), x) - pre.begin();
    i--;
    ll preDay = -1;
    for(; i >= 1; i--) {
      ll curDay = (x - pre[i])/i;
      res += i * (curDay - preDay);
      preDay = curDay;
    }
    cout << res << '\n';
  }
  return 0;
}