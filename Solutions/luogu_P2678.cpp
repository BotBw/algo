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

int l, n, m;
vector<int> d;

bool check(int mi) {
  int pre = 0;
  int remove = 0;
  FOR(i, 1, n) {
    if(d[i] - d[pre] < mi) remove++;
    else pre = i;
  }
  return remove <= m;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> l >> n >> m;
  d = vector<int>(n + 2);
  FOR(i, 1, n) cin >> d[i];
  d[n + 1] = l;

  int ll = 0, rr = l;
  while(ll < rr) {
    int mi = (ll + rr + 1) / 2;
    if(check(mi)) ll = mi;
    else rr = mi - 1;
  }
  cout << ll;
  return 0;
}