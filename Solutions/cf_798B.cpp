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
    int n;
    cin >> n;
    set<int> s;
    vector<int> arr(n);
    FOR(i, 0, n-1) {
      int x; 
      cin >> x;
      arr[i] = x;
      s.insert(x);
    }
    if(n == 1) {
      cout << "-1\n";
      continue;
    }
    FOR(i, 0, n-3) {
      // debug(i, arr[i], s);
      auto it = s.begin();
      if(*it == arr[i]) it++;
      cout << *it << ' ';
      s.erase(it);
    }
    auto it = s.begin();
    int a = *it;
    it++;
    int b = *it;
    if(a == arr[n-2] || b == arr[n-1]) swap(a, b);
    cout << a << ' ' << b << '\n';
  }
  return 0;
}