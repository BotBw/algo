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

int n, k;
vector<int> l;

bool check(int mi) {
  int res = 0;
  FOR(i, 0, n-1) {
    res += l[i]/mi;
  }
  return res >= k;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  l = vector<int>(n);
  int ll = 0, r = 1e8;
  FOR(i, 0, n-1) cin >> l[i], r = max(r, l[i]);
  while(ll < r) {
    int mi = (ll + r + 1) / 2;
    if(check(mi)) ll = mi;
    else r = mi - 1;
  }
  cout << ll;
  return 0;
}