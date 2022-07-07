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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n;
    cin >> n;
    VI a(n);
    FOR(i, 0, n-1) cin >> a[i];
    if(n & 1) {
      cout << "NO\n";
      continue;
    }
    unordered_map<int, int> hash;
    FOR(i, 0, n-1) {
      hash[a[i]]++;
    }
    bool flag = true;
    for(auto p:hash) {
      if(p.second > n/2) {
        flag = false;
        break;
      }
    }
    // debug(hash);
    if(!flag) {
      cout << "NO\n";
      continue;
    }
    sort(a.begin(), a.end());
    VI res(n);
    int j = 0;
    for(int i = 0; i < n/2; i++) {
      res[j++] = a[i];
      res[j++] = a[i + n/2];
    }
    flag = true;
    debug(res);
    FOR(i, 0, n-1) {
      int l = i - 1;
      int r = i + 1;
      if(l == -1) l = n-1;
      if(r == n) r = 0;
      if((i & 1) && !(res[i] > res[l] && res[i] > res[r])) {
        // debug(i, l, r, a[i], a[l], a[r]);
        flag = false;
        break;
      } else if(!(i & 1) && !(res[i] < res[l] && res[i] < res[r])) {
        flag = false;
        break;
      }
    }
    if(flag) {
      cout << "YES\n";
      FOR(i, 0, n-1) cout << res[i] << ' ';
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}