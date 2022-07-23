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
    unordered_map<char, int> cnt;
    FOR(i, 1, n * 2 + 1) {
      string tx;
      cin >> tx;
      for(auto c:tx) cnt[c]++;
    }
    for(auto p:cnt) {
      if(p.second & 1) {
        cout << p.first << endl;
        break;
      }
    }
  }
  return 0;
}