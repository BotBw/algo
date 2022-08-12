#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    if(n & 1) {
      cout << "-1\n";
      continue;
    }
    int c = n/2 ^ 1;
    int b = n/2 ^ c;
    int a = b;
    cout << a << ' ' << b << ' ' << c << '\n';
  }
  return 0;
}