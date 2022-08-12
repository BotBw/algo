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

int n, m;
string s;
vector<int> a;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    cin >> n >> m;
    a = vector<int>(n + 1);
    s = string(m, 'B');
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) {
      int id = a[i];
      id--;
      if(id >= m/2) id = m - id - 1;
      if(s[id] != 'A') s[id] = 'A';
      else if(s[m - id - 1] != 'A') s[m - id - 1] = 'A';
    }
    cout << s << '\n';
  }
  return 0;
}