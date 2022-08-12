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

int N, M;
vector<int> h;

bool check(ll mi) {
  ll cut = 0;
  FOR(i, 0, N-1) {
    if(mi < h[i]) cut += h[i] - mi;
  }
  return cut >= M;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> M;
  h = vector<int>(N);
  ll r = 0;
  FOR(i, 0, N-1) cin >> h[i], r = max(r, (ll)h[i]);
  ll l = 0;
  debug(l, r);
  while(l < r) {
    ll mi = (l + r + 1) >> 1;
    if(check(mi)) l = mi;
    else r = mi - 1;
  }
  cout << l;
  return 0;
}