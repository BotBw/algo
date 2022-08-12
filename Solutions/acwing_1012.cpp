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
  int n;
  cin >> n;
  vector<pii> work;
  FOR(i, 1, n) {
    int a, b;
    cin >> a >> b;
    work.push_back({a, b});
  }
  sort(work.begin(), work.end());
  vector<int> cur;
  FOR(i, 0, n-1) {
    int bi = work[i].second;
    if(cur.empty() || bi >= cur.back()) {
      cur.push_back(bi);
    } else {
      *upper_bound(cur.begin(), cur.end(), bi) = bi;
    }
  }
  cout << cur.size();
  return 0;
}