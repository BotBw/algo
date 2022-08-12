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
  int w, n;
  cin >> w >> n;
  vector<int> a(n);
  for(auto &v:a) cin >> v;
  map<int, int> hash;
  for(auto v:a) hash[v]++;
  int res = 0;
  sort(a.begin(), a.end(), greater<int>());
  debug(a);
  for(int i = 0; i < (int)a.size(); i++) {
    if(!hash.count(a[i])) continue;
    hash[a[i]]--;
    if(hash[a[i]] == 0) hash.erase(a[i]);
    res++;
    if(a[i] < w) {
      auto it = hash.upper_bound(w - a[i]);
      if(it != hash.begin()) {
        it--;
        auto key = it->first;
        if(key <= w - a[i]) {
          hash[key]--;
          if(hash[key] == 0) hash.erase(key);
        } 
      }
    }
  }
  debug(hash);
  cout << res;
  return 0;
}