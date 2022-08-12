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
    int n;
    cin >> n;
    string s(n + 1, 0), te(n + 1, 0);
    cin >> (s.data() + 1) >> (te.data() + 1);
    int i = 1, j = 1;
    int bcnt_i, bcnt_j;
    bcnt_i = bcnt_j = 0;
    bool flag = true;
    while (i <= n && j <= n) {
      while(i <= n && s[i] == 'b') i++, bcnt_i++;
      while(j <= n && te[j] == 'b') j++, bcnt_j++;
      if(s[i] != te[j]) {
        flag = false;
        break;
      } else {
        if(s[i] == 'a') {
          if(bcnt_i > bcnt_j) {
            flag = false;
            break;
          } else {
            i++, j++;
          }
        } else if(s[i] == 'c') {
          if(bcnt_i < bcnt_j) {
            flag = false;
            break;
          } else {
            i++, j++;
          }
        }
      }
    }
    while(i <= n && s[i] == 'b') i++;
    while(j <= n && te[j] == 'b') j++;
    if(!(i == n + 1 && j == n + 1)) flag = false;
    debug(i, j);
    if(flag) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}