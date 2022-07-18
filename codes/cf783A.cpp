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

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    int n, m;
    cin >> n >> m;
    if(m == n) {
      cout << n + m - 2 << endl;
    } else {
      if((m == 1 && n > 2) || (n == 1 && m > 2)) {
        cout << -1 << endl;
      } else {
        int k = abs(n - m);
        int p = min(n, m);
        cout << p*2 - 2 + (k + 1)/2 + k/2*3 << endl;
      }
    }
  } 
  return 0;
}