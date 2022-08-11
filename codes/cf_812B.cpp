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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    vector<int> b;
    int l = 1, r = n;
    while(l <= r) {
      if(a[l] <= a[r]) b.push_back(a[l]), l++;
      else b.push_back(a[r]), r--;
    }
    cout << (is_sorted(b.begin(), b.end()) ? "YES\n" : "NO\n");
  }
  return 0;
}