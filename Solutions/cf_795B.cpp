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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n;
    cin >> n;
    vector<PII> a(n + 1);
    FOR(i, 1, n) {
      a[i].second = i;
      cin >> a[i].first;
    }
    debug(a);
    VI res(n + 1);
    bool flag = true;
    int l = 1, r = 1;
    for(; r <= n + 1; r++) {
      if(r == n + 1 || a[l].first != a[r].first) {
        debug(l, r);
        if(r - l + 1 <= 2) {
          cout << "-1\n";
          flag = false;
          break;
        }
        FOR(i, l, r-1) {
          int j = i - 1;
          if(j == l - 1) j = r-1;
          res[a[i].second] = a[j].second;
        }
        l = r;
      }
    }
    if(flag) {
      FOR(i, 1, n) cout << res[i] << ' ';
      cout << '\n';
    }
  }
  return 0;
}