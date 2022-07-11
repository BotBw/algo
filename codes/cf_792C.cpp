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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    FOR(i, 1, n)
      FOR(j, 1, m)
        cin >> a[i][j];
    vector<int> badPos;
    FOR(i, 1, n) {
      auto tmp = a[i];
      sort(tmp.begin() + 1, tmp.end());
      FOR(j, 1, m) {
        if(tmp[j] != a[i][j]) {
          badPos.push_back(j);
        }
      }
      if(!badPos.empty()) break;
    }
    int sz = badPos.size();
    if(!sz) {
      cout << "1 1\n";
    } else if(sz > 2) {
      cout << "-1\n";
    } else {
      FOR(i, 1, n) {
        swap(a[i][badPos[1]], a[i][badPos[0]]);
      }
      bool flag = true;
      FOR(i, 1, n) {
        FOR(j, 2, m) {
          if(a[i][j-1] > a[i][j]) {
            flag = false;
            goto bbreak;
          }
        }
      }
    bbreak:
      if(flag) cout << badPos[0] << " " << badPos[1] << "\n";
      else cout << "-1\n";
    }
  }
  return 0;
}