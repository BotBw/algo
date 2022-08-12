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

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    string s;
    cin >> s;
    int cnt0 = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '0') cnt0++;
    }
    int cnt1 = s.size() - cnt0;
    int lo = 0, hi = cnt1;
    while(lo < hi) {
      int mi = (lo + hi + 1) / 2;
      // debug(lo, hi, mi);
      auto check = [&](int mi) {
        int cur_0 = 0, cur_1 = 0;
        for(int l = 0, r = 0; r < s.size(); r++) {
          if(s[r] == '0') cur_0++;
          else cur_1++;
          while(l <= r && cur_0 > cnt1 - mi) {
            if(s[l] == '0') cur_0--;
            else cur_1--;
            l++;
          }
          if(cur_0 <= cnt1 - mi && cur_1 >= mi) {
            // debug(l, r, cur_1, mi);
            return true;
          }
        }
        return false;
      };
      if(check(mi)) lo = mi;
      else hi = mi - 1;
    }
    cout << cnt1 - lo << "\n";
  }
  return 0;
}