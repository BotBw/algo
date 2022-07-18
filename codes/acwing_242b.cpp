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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int lowbit(int x) {
  return x & -x;
}
vector<LL> t;
void update(int x, LL d) {
  for(; x <= n; x += lowbit(x)) {
    t[x] += d;
  }
}

int query(int x) {
  int res = 0;
  for(; x; x -= lowbit(x)) {
    res += t[x];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  t = vector<LL>(n + 1);
  vector<LL> a(n + 1), b(n + 1);
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) b[i] = a[i] - a[i-1];
  FOR(i, 1, n) update(i, b[i]);
  FOR(i, 1, m) {
    char op;
    cin >> op;
    if(op == 'C') {
      int l, r;
      LL d;
      cin >> l >> r >> d;
      update(l, d);
      update(r + 1, -d);
    } else {
      int x;
      cin >> x;
      cout << query(x) << endl;
    }
  }
  return 0;
}