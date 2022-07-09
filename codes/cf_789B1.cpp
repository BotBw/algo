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
    string s;
    cin >> s;
    int cnt = 0, evenCnt = 0;
    int i = 0, j = 0;
    int res = 0;
    bool hasPrev = false;
    while(j < n) {
      while(j < n && s[i] == s[j]) j++, cnt++;
      if(cnt & 1) {
        if(hasPrev) res += (evenCnt + 1);
        hasPrev ^= 1;
        debug(i, j, evenCnt, res);
        evenCnt = 0;
      } else {
        evenCnt++;
      }
      cnt = 0;
      i = j;
    }
    cout << res << '\n';
  }
  return 0;
}