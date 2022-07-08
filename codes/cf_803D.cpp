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

bool check(int l, int mi) {
  cout << "? " << l << " " << mi << endl;
  int cnt = 0;
  FOR(i, 1, mi - l + 1) {
    int x;
    cin >> x;
    if(l <= x && x <= mi) cnt++;
  }
  return cnt & 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n;
    cin >> n;
    int l = 1, r = n;
    while(l < r) {
      int mi = (l + r) >> 1;
      if(check(l, mi)) r = mi;
      else l = mi + 1;
    }
    cout << "! " << l << endl;
  }
  return 0;
}