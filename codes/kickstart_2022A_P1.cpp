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
    string a, b;
    cin >> b >> a;
    int m = a.size(), n = b.size();
    int l = 0, r = 0;
    int res = 0;
    while(l < m && r < n) {
      if(a[l] == b[r]) l++, r++;
      else l++, res++;
    }
    res += m - l;
    cout << "Case #" << _ << ": ";
    if(r != n) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << res << '\n';
    }
  }
  return 0;
}