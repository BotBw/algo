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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for(auto &e:a) cin >> e;
  ll res = 0;
  for(int i = 1; i < n; i++) {
    if(a[i-1] + a[i] > x) {
      int eat = min(a[i], a[i-1] + a[i] - x);
      a[i] -= eat;
      res += eat;
      if(a[i-1] + a[i] > x) {
        res += a[i-1] + a[i] - x;
      }
    }
  }
  cout << res;
  return 0;
}