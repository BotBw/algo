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

int n, C;
vector<int> a;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> C;
  a = vector<int>(n);
  FOR(i, 0, n-1) cin >> a[i];
  sort(a.begin(), a.end());
  ll res = 0;
  FOR(i, 0, n-1) {
    int A = a[i];
    int B = A - C;
    res += upper_bound(a.begin(), a.end(), B) - lower_bound(a.begin(), a.end(), B);
  }
  cout << res;
  return 0;
}