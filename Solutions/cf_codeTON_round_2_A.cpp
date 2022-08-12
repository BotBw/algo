#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0 && a[i] == b[j]) {
      i--;
      j--;
    }
    if(j == -1) {
      cout << "YES\n";
      continue;
    } else if(j != 0) {
      cout << "NO\n";
      continue;
    }
    bool cnt_1 = false, cnt_0 = false;
    FOR(k, 0, i) {
      if(a[k] == '1') cnt_1 = true;
      if(a[k] == '0') cnt_0 = true;
    }
    if(cnt_1 && cnt_0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}