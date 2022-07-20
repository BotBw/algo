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
    vector<int> a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    int i = 1;
    if(n & 1) i++;
    for(; i <= n - 1; i += 2) {
      if(a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    }
    bool isSorted = true;
    FOR(i, 1, n-1) {
      if(a[i] > a[i + 1]) {
        isSorted = false;
        break;
      }
    }
    cout << (isSorted ? "YES" : "NO") << '\n';
  }
  return 0;
}