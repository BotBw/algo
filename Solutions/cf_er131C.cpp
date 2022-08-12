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
template <class T> using V = vector<T>;

bool check(LL mi, V<LL> &wks, LL num_task) {
  LL n = wks.size() - 1;
  FOR(i, 1, n) {
    if(wks[i] < mi) num_task -= (wks[i] + (mi - wks[i])/2);
    else num_task -= mi;
  }
  return num_task <= 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  LL T;
  cin >> T;
  FOR(t, 1, T) {
    LL n, m;
    cin >> n >> m;
    V<LL> worker(n + 1);
    FOR(i, 1, m) {
      LL t_id;
      cin >> t_id;
      worker[t_id] ++;
    }
    LL l = 1, r = m * 2;
    while(l < r) {
      LL mi = (l + r ) >> 1;
      if(check(mi, worker, m)) r = mi;
      else l = mi + 1;
    }
    cout << l << '\n';
  }
  return 0;
}