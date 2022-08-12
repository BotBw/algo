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
    string str;
    cin >> str;
    int l = (n - 1)/2;
    int cnt = 1, r = l;
    if(!(n & 1)) {r ++, cnt++;}
    while(l - 1 >= 0 && str[l-1] == str[(n-1)/2]) {
      l--, r++;
      cnt += 2;
    }
    cout << cnt << '\n';
  }
  return 0;
}