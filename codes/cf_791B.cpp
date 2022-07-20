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

ll n, q;

unordered_map<ll, ll> q1;
vector<ll> q2;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  vector<ll> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  ll res = 0;
  FOR(i, 1, n) res += a[i];
  FOR(i, 1, q) {
    int t;
    cin >> t;
    if(t == 1) {
      ll ii, x;
      cin >> ii >> x;
      if(q2.empty()) {
        if(q1.count(ii)) {
          res += x - q1[ii];
        } else {
          res += x - a[ii];
        }
      } else {
        if(q1.count(ii)) {
          res += x - q1[ii];
        } else {
          res += x - q2.back();
        }
      }
      q1[ii] = x;
    } else if(t == 2) {
      ll x;
      cin >> x;
      q2.push_back(x);
      q1.clear();
      res = n * x;
    }
    cout << res << '\n';
  }
  return 0;
}