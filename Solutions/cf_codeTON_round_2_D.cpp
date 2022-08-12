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
  FOR(_, 1, tt) {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> c(n + 1, vector<ll>(m + 1));
    FOR(i, 1, n) {
      FOR(j, 1, m) cin >> c[i][j];
    }
    vector<ll> check(n + 1);
    FOR(i, 1, n) {
      FOR(j, 1, m) {
        c[i][j] += c[i][j-1];
      }
      FOR(j, 1, m) check[i] += c[i][j];
    }
    debug(check);
    int k = min_element(check.begin() + 1, check.end()) - check.begin();
    ll cnt = ((k == 1) ? check[2] : check[1]) -  check[k];
    cout << k << " " << cnt << endl;
  }
  return 0;
}