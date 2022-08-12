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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    int n;
    cin >> n;
    unordered_set<int> hash;
    vector<int> a;
    for(int i = 1; i <= n; i++) {
      if(hash.count(i)) continue;
      a.push_back(i);
      hash.insert(i);
      for(int j = i * 2; j <= n; j *= 2) {
        if(hash.count(j)) continue;
        a.push_back(j);
        hash.insert(j);
      }
    }
    cout << 2 << endl;
    for(auto v:a) cout << v << " ";
    cout << endl;
  }
  return 0;
}