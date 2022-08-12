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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 2, n) {
    if(a[i] % a[i-1] != 0) {
      cout << "NO\n";
      return;
    }
    a[i] = a[i-1];
  }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1 ,tt) solve();
  return 0;
}