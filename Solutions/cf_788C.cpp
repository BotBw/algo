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

int n;
vector<int> a, b, c;
const int MOD = 1e9 + 7;
vector<int> dsu;

int find(int x) {
  return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void solve() {
  cin >> n;
  a = b = c = dsu = vector<int>(n + 1);
  FOR(i, 1, n) dsu[i] = i;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  FOR(i, 1, n) cin >> c[i];
  FOR(i, 1, n) {
    if(c[i] == 0) {
      if(a[i] == b[i]) {
        int pa = find(a[i]);
        dsu[pa] = 0;
      } else {
        int pa = find(a[i]), pb = find(b[i]);
        if(!pa || !pb) dsu[pa] = dsu[pb] = 0;
        else dsu[pa] = pb;
      }
    } else {
      int pc = find(c[i]);
      dsu[pc] = 0;
    }
  }
  unordered_set<int> s;
  FOR(i, 1, n) {
    if(c[i] == 0) {
      s.insert(find(a[i]));
    }
  }
  int res = 1;
  s.erase(0);
  FOR(i, 1, s.size()) {
    res *= 2;
    res %= MOD;
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) solve();
  return 0;
}