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
  vector<int> a(n);
  for(auto &v:a) cin >> v;
  sort(a.begin(), a.end());
  vector<int> lst, sz;
  FOR(i, 0, n-1) {
    int j = upper_bound(lst.begin(), lst.end(), a[i] - 1) - lst.begin();
    if(j == 0) {
      lst.push_back(a[i]);
      sz.push_back(1);
    } else {
      j--;
      if(lst[j] == a[i] - 1) {
        lst[j]++;
        sz[j]++;
      } else {
        lst.push_back(a[i]);
        sz.push_back(1);
      }
    }
    debug(lst, sz);
  }
  int res = INT_INF;
  for(auto v:sz) res = min(res, v);
  cout << res;
  return 0;
}