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


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int x;
    cin >> x;
    if(x == 1) {
      cout << "3\n";
      continue;
    }
    int y = 0;
    int i = 0;
    for(; i < 32; i++) {
      if(x >> i & 1) {
        y |= 1 << i;
        break;
      }
    }
    debug(y, i);
    if(x - (1 << i) == 0) y |= 1;
    cout << y << '\n';
  }
  return 0;
}