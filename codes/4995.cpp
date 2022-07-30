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
  int n;
  cin >> n;
  vector<int> h(n + 1);
  FOR(i, 1, n) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());
  int l = 0, r = n;
  bool l2r = true;
  ll res = 0;
  while(l < r) {
    ll d = abs(h[r] - h[l]);
    res += d*d;
    if(l2r) {
      l++;
      l2r = false;
    } else {
      r--;
      l2r = true;
    }
  }
  cout << res << endl;
  return 0;
}