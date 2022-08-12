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

struct node {
  int l, r;
  int val;
};

vector<node> tx, ty;

void pushup(vector<node> &t, int i) {
  t[i].val = t[i*2].val + t[i*2 + 1].val;
}

void build(vector<node> &t, int i, int l, int r) {
  t[i] = {l, r, 0};
  if(l == r) return;
  int mi = (l + r) / 2;
  build(t, i*2, l, mi);
  build(t, i*2 + 1, mi + 1, r);
  pushup(t, i);
}

void update(vector<node> &t, int i, int x, int val) {
  if(t[i].l == t[i].r && t[i].l == x) {
    t[i].val += val;
    return;
  }
  int mi = (t[i].l + t[i].r) / 2;
  if(x <= mi) update(t, i*2, x, val);
  else update(t, i*2 + 1, x, val);
  pushup(t, i);
}

int query(vector<node> &t, int i, int l, int r) {
  if(l <= t[i].l && t[i].r <= r) return t[i].val;
  int mi = (t[i].l + t[i].r) / 2;
  int res = 0;
  if(l <= mi) res += query(t, i * 2, l, r);
  if(mi + 1 <= r) res += query(t, i*2 + 1, l, r);
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n >> q;
  tx = ty = vector<node>(n * 4);
  build(tx, 1, 1, n);
  build(ty, 1, 1, n);
  FOR(i, 1, q) {
    int t;
    cin >> t;
    if(t == 1) {
      int x, y;
      cin >> x >> y;
      update(tx, 1, x, 1);
      update(ty, 1, y, 1);
    } else if(t == 2) {
      int x, y;
      cin >> x >> y;
      update(tx, 1, x, -1);
      update(ty, 1, y, -1);
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int qx = query(tx, 1, x1, x2);
      int qy = query(ty, 1, y1, y2);
      debug(qx, qy);
      if(qx == (x2 - x1 + 1) || qy == (y2 - y1 + 1)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  return 0;
}