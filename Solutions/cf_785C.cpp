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

const int N = 4e4 + 5;

vector<int> bases;
int num[5];
int tenTo[5] = {1, 10, 100, 1000, 10000};

void helper(int hi, int lo) {
  if(hi < lo) {
    int res = 0;
    for(int i = 0; i < 5; i++) {
      res += num[i]*tenTo[i];
    }
    bases.push_back(res);
    return ;
  }
  FOR(i, 0, 9) {
    num[hi] = num[lo] = i;
    helper(hi - 1, lo + 1);
  }
}

void generate(int hi, int maxV) {
  for(int i = 1; i <= maxV; i++) {
    num[hi] = num[0] = i;
    helper(hi - 1, 1);
  }
}

void init() {
  for(int hi = 0; hi <= 4; hi++) {
    if(hi == 4) generate(hi, 4);
    else generate(hi, 9);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  init();
  int tt;
  cin >> tt;
  vector<int> dp(N + 1);
  const int MOD = 1e9 + 7;
  dp[0] = 1;
  for(int i = 0; i < bases.size(); i++) {
    FOR(j, 0, N) {
      if(j < bases[i]) continue;
      dp[j] += dp[j-bases[i]];
      dp[j] %= MOD;
    }
  }
  FOR(t, 1, tt) {
    int n;
    cin >> n;
    cout << dp[n] << endl;
  }
  return 0;
}