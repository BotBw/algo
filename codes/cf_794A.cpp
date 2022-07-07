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
  FOR(t, 1 ,T) {
    int n;
    cin >> n;
    VI a(n);
    int sum = 0;
    FOR(i, 0, n-1) cin >> a[i], sum += a[i];
    int flag = false;
    FOR(i, 0, n-1) {
      if(sum - a[i] == (n - 1) * a[i]) {
        flag = true;
        break;
      }
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}