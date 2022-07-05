#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
typedef long long LL;
typedef pair<LL, LL> PLL;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    string res;
    int i = 0, j = 0, cur_i = 0, cur_j = 0;
    // debug(a, b);
    while(i < n && j < m) {
      if(cur_i == k) {
        res.push_back(b[j++]);
        cur_j++;
        cur_i = 0;
        continue;
      }
      if(cur_j == k) {
        res.push_back(a[i++]);
        cur_i++;
        cur_j = 0;
        continue;
      }
      if(a[i] <= b[j]) {
        res.push_back(a[i++]);
        cur_i++;
        cur_j = 0;
      } else {
        res.push_back(b[j++]);
        cur_j++;
        cur_i = 0;
      }
    }
    cout << res << "\n";
  }
  return 0;
}