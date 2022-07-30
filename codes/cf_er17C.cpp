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

int n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    cin >> n;
    vector<int> a(n), b(n);
    FOR(i, 0, n-1) {
      cin >> a[i] >> b[i];
    }
    int l = 0, r = n;
    auto check = [&](int mi) {
      int cur = 0;
      FOR(i, 0, n-1) {
        if(mi - a[i] - 1 <= cur && cur <= b[i]) cur++;
      }
      return cur >= mi;
    };
    while(l < r) {
      int mi = (l + r + 1) >> 1;
      if(check(mi)) l = mi;
      else r = mi - 1;
    }
    cout << l << endl;
  }
  return 0;
}