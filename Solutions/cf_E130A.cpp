#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    FOR(i, 1, n) {
      int a;
      cin >> a;
      sum += a;
    }
    cout << -min(0, m - sum) << '\n';
  }
  return 0;
}