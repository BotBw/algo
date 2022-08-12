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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    FOR(i, 0, n-1) cin >> a[i];
    ll res = 0;
    FOR(i, 0, n-1) {
      res += a[i] / k;
      a[i] %= k;
    }
    sort(a.begin(), a.end(), greater<int>());
    int j = n - 1;
    for(int i = 0; i < n; i++) {
      while(a[i] + a[j] < k && i < j) j--;
      debug(i, j);
      if(i == j) break;
      res++;
      j--;
      if(i >= j) break;
    }
    cout << res << endl;
  }
  return 0;
}