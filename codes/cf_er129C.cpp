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
    vector<PII> ab(n);
    FOR(i, 0, n-1) cin >> ab[i].first;
    FOR(i, 0, n-1) cin >> ab[i].second;
    vector<PII> res;
    int cnt = 0;

    FOR(i, 0, n-1) {
      int j = i-1;
      while(j >= 0 && ab[j] > ab[j+1]) {
        swap(ab[j], ab[j+1]);
        cnt++;
        res.push_back({j+1, j+2});
        j--;
      }
    }
    if(cnt > 1e4) {
      cout << "-1\n";
      continue;
    }
    bool isSorted = true;
    FOR(j, 1, n-1) {
      if(ab[j-1].second > ab[j].second) {
        isSorted = false;
        break;
      }
    }
    debugif(t == 22, ab);
    if(isSorted) {
      cout << res.size() << '\n';
      for(auto v:res) {
        cout << v.first << ' ' << v.second << '\n';
      }
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}