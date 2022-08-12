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

int n, m;
vector<int> a;

int bin_s(int l, int r, int val) {
  while(l < r) {
    int mi = (l + r)/2;
    if(a[mi] >= val) r = mi;
    else l = mi + 1;
  }
  return l;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  a = vector<int>(n);
  FOR(i, 0, n-1) cin >> a[i];
  FOR(i, 1, m) {
    int val;
    cin >> val;
    int rank = bin_s(0, n-1, val);
    if(a[rank] == val) cout << rank + 1 << ' ';
    else cout << -1 << ' ';
  }
  return 0;
}