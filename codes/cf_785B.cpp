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
    string s;
    cin >> s;
    unordered_set<char> hash;
    for(auto c:s) hash.insert(c);
    int char_cnt = hash.size();
    hash.clear();
    for(int i = 0; i < char_cnt; i++) {
      hash.insert(s[i]);
    }
    bool ok = true;
    if(hash.size() != char_cnt) ok = false;
    if(ok) {
      for(int i = char_cnt; i < s.size(); i++) {
        if(s[i] != s[i-char_cnt]) {
          ok = false;
          break;
        }
      }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}