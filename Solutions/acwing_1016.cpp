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
  vector<int> a(n + 1), dp(n + 1), sum(n + 1);
  FOR(i, 1, n) cin >> a[i];
  int res = 0;
  FOR(i, 1, n) {
    dp[i] = 1;
    sum[i] = a[i];
    FOR(j, 1, i - 1) {
      if(a[j] < a[i]) {
        if(dp[i] < dp[j] + 1) {
          sum[i] = max(sum[i], sum[j] + a[i]);
          dp[i] = dp[j] + 1;
        }
      }
    }
    res = max(sum[i], res);
  }
  cout << res;
  return 0;
}