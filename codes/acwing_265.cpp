#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
ll ans;
#ifdef LEET
#include "leet.h"
#else
int main() {
  int n;
  set<int> s;
  cin >> n;
  cin >> ans;
  s.insert(ans);
  FOR(i, 2, n) {
    int ai;
    cin >> ai; 
    auto it = s.lower_bound(ai);
    if(it == s.end()) {
      it--;
      ans += abs(*it - ai);
    } else if (it == s.begin()) {
      ans += abs(*it - ai);
    } else {
      auto it1 = it;
      it--;
      ans += min(abs(*it - ai), abs(*it1 - ai));
    }
    s.insert(ai);
  }
  cout << ans;
  return 0;
}
#endif