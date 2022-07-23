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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    ll res = 0;
    FOR(i, 1, n) {
      if(a[i] > b[i]) swap(a[i], b[i]);
    }
    FOR(i, 1, n-1) {
      res += abs(a[i + 1] - a[i]) + abs(b[i + 1] - b[i]);
    }
    cout << res << endl;
  }
  return 0;
}