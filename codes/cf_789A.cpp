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
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n;
    cin >> n;
    int zero_cnt = 0;
    vector<int> a(n + 1);
    FOR(i, 1, n) {
      int x;
      cin >> x;
      a[i] = x;
      if(!x) zero_cnt++;
    }
    if(zero_cnt) cout << (n - zero_cnt) << '\n';
    else {
      unordered_set<int> se;
      bool flag = false;
      FOR(i, 1, n) {
        if(se.count(a[i])) {
          flag = true;
          break;
        }
        se.insert(a[i]);
      }
      if(flag) cout << n << '\n';
      else cout << (n + 1) << '\n';
    }
  }
  return 0;
}