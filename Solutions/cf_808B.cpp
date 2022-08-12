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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    bool ok = true;
    FOR(i, 1, n) {
      int ai_min = (l + i - 1) / i;
      int ai_max = r/i;
      if(ai_min <= ai_max) a[i] = ai_min * i;
      else {
        ok = false;
        break;
      }
    }
    if(ok) {
      cout << "YES\n";
      FOR(i, 1, n) cout << a[i] << ' ';
      cout << '\n';
    } else cout << "NO\n";
  }
  return 0;
}