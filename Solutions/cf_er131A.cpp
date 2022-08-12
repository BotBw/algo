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
    int data = 0;
    FOR(i, 1, 4) {
      data = data << 1;
      int x;
      cin >> x;
      data |= x;
    }
    int res = 0;
    switch(data) {
      case 0:
        res = 0;
        break;
      case 15:
        res = 2;
        break;
      default:
      res = 1;
    }
    cout << res << '\n';
  }
  return 0;
}