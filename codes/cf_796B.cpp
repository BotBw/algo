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
    VI a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    int oddCnt = 0;
    int lowestOne = 31;
    FOR(i, 1, n) {
      if(a[i] & 1) oddCnt++;
      else {
        FOR(j, 0, 31) {
          if(a[i] >> j & 1) {
            lowestOne = min(lowestOne, j);
          }
        }
      }
    }
    if(oddCnt) {
      cout << n - oddCnt << '\n';
    } else {
      cout << lowestOne + n - 1 << '\n';
    }
  }
  // debug(1049600/8, 33792/8, 1280/8);
  return 0;
}