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
  vector<int> h(n+1), dp(n+1);
  FOR(i, 1, n) cin >> h[i];
  FOR(i, 1, n) {
    if(h[i] > h[i-1]) {
      dp[i] = dp[i-1] + h[i] - h[i-1];
    } else {
      dp[i] = dp[i-1];
    }
  }
  cout << dp[n] << endl;
  return 0;
}