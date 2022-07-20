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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<string> con {"aa", "aaa", "bb", "bbb"};

vector<bool> dp;
string s;

void solve() {
  cin >> s;
  int n = s.size();
  s = " " + s;
  dp = vector<bool>(n + 1);
  dp[0] = true;
  FOR(i, 1, n) {
    for(const auto &token:con) {
      if(i - (int)token.size() + 1 < 0) continue;
      if(s.substr(i - token.size() + 1, token.size()) == token) {
        dp[i] = dp[i - token.size()];
        if(dp[i]) break;
      } 
    }
  }
  cout << (dp[n] ? "YES" : "NO") << '\n';
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) solve();
  return 0;
}