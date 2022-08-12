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

const int N = 1e5 + 10;
vector<pii> ys;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ys.push_back({0, 0});
  for(int i = 1; i < 2*N/i; i++) {
    ys.push_back({i * i, i});
  }
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n;
    cin >> n;
    int k = n;
    vector<int> res(n);
    while(n > 0) {
      int r = n - 1;
      // l == y*y - r
      auto y = lower_bound(ys.begin(), ys.end(), pii{r, -1});
      int l = y->first - r;
      FOR(i, l, r) {
        res[i] = y->first - i;
      }
      n = l;
    }
    FOR(i, 0, k-1) cout << res[i] << " \n"[i == k-1];
  }
  return 0;
}