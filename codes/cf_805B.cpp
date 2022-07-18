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
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    string s;
    cin >> s;
    unordered_set<char> mem;
    int res = 1;
    for(int i = 0; i < s.size(); i++) {
      if(!mem.count(s[i]) && mem.size() == 3) {
        mem.clear();
        res++;
      }
      mem.insert(s[i]);
    }
    cout << res << endl;
  }
  return 0;
}