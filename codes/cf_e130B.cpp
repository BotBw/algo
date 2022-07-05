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
  int n, q;
  cin >> n >> q;
  vector<ll> ps(n+1);
  FOR(i, 1, n) cin >> ps[i];
  sort(ps.begin() + 1, ps.end());
  vector<ll> sum(ps);
  FOR(i, 1, n) sum[i] += sum[i-1];
  FOR(i, 1, q) {
    int x, y;
    cin >> x >> y;
    cout << sum[n - x + y] - sum[n - x] << '\n';
  }
  return 0;
}