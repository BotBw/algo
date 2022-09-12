#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#include "leet.h"
#include "mySTL.h"
#else
#define debug(...)
#endif
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
#define pb(x) push_back(x)
#define pf(x) push_front(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct item {
  int v, w, s;
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<item> a(n + 1);
  FOR(i, 1, n) cin >> a[i].v >> a[i].w >> a[i].s;
  vector<ll> f(m + 1);
  FOR(i, 1, n) {
    _FOR(k, m, a[i].v) {
      FOR(j, 0, a[i].s) {
        if(k - j * a[i].v >= 0) f[k] = max(f[k], f[k - j * a[i].v] + j * a[i].w);
      }
    }
  }
  cout << f[m] << endl;
  return 0;
}