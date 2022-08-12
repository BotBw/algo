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
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    FOR(i, 1, m) cin >> a[i];
    int day = 0;
    sort(a.begin() + 1, a.end());
    priority_queue<int> q;
    FOR(i, 2, m) {
      int diff = a[i] - a[i-1] - 1;
      if(diff > 0) q.push(diff);
    }
    int diff = a[1] + n - a[m] - 1;
    if(diff > 0) q.push(diff);
    int protec = 0;
    while(q.size()) {
      auto elem = q.top();
      q.pop();
      elem -= 2*day;
      if(elem > 0) {
        protec += max(1, elem - 1);
      }
      day += 2;
    }
    cout << n - protec << endl;
  }
  return 0;
}