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
  FOR(t, 1, T) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = n - 1;
    while(l >= 0 && s[l] != '1') l--;
    if(k >= n - l - 1) {
      k -= n - l - 1;
      swap(s[l], s[n-1]);
    }
    int h = 0;
    while(h < n && s[h] != '1') h++;
    if(k >= h & h != n-1) {
      swap(s[0], s[h]);
    }
    int res = 0;
    FOR(i, 0, n-2) {
      string num = s.substr(i, 2);
      if(num == "01") res += 1;
      else if(num == "10") res += 10;
      else if(num == "11") res += 11;
    }
    cout << res << '\n';
  }
  return 0;
}