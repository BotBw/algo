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
    iota(a.begin(), a.end(), 0);

    cout << n << endl;
    FOR(i, 1, n) cout << a[i] << " \n"[i == n];
    FOR(i, 1, n-1) {
      swap(a[i], a[i+1]);
      FOR(j, 1, n) cout << a[j] << " \n"[j == n];
    }
  }
  return 0;
}