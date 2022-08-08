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
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n;
    cin >> n;
    if(n == 1) cout << 2 << endl;
    else if(n % 3 == 0) cout << n / 3 << endl;
    else if(n % 3 == 1) cout << (n - 4) / 3 + 2 << endl;
    else if(n % 3 == 2) cout << (n - 2) / 3 + 1 << endl;
  }
  return 0;
}