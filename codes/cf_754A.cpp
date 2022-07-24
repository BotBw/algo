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

char c[1005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    int n;
    cin >> n;
    cin >> (c + 1);
    int zero, one;
    zero = one = 0;
    vector<int> res;
    FOR(i, 1, n) {
      if(c[i] == '1') one++;
      if(c[i] == '0') zero++;
    }
    FOR(i, 1, zero) {
      if(c[i] != '0') res.push_back(i);
    }
    FOR(i, zero + 1, n) {
      if(c[i] != '1') res.push_back(i);
    }
    if(res.size()) cout << 1 << endl;
    cout << res.size() << ' ';
    for(auto v:res) cout << v << ' ';
    cout << endl;
  }
  return 0;
}