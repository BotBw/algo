#include "bits/stdc++.h"

struct node {
  ll sum, lazy;
};

node ie() {
  return {0, 0};
}

void push_up(node &a, const node &b, const node &c) {
  a.sum = b.sum + c.sum;
}

void push_down(node &a, node &b, int lenb, node &c, int lenc) {
  ll lazy = a.lazy;
  a.lazy = 0;
  b.lazy += lazy;
  b.sum += lenb * lazy;
  c.lazy += lazy;
  c.sum += lenc * lazy;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<node> a(n + 1);
  FOR(i, 1, n) cin >> a[i].sum;
  segtree<node, push_up, push_down, ie> seg(1, n, a);
  FOR(i, 1, m) {
    debug(i);
    int op;
    cin >> op;
    if(op == 1) {
      int x, y, k;
      cin >> x >> y >> k;
      if(x > y) swap(x, y);
      seg.update(x, y, [&](int l, int r, node &tag) { tag.lazy += k; tag.sum += (r - l + 1) * k; });
    } else {
      int x, y;
      cin >> x >> y;
      if(x > y) swap(x, y);
      cout << seg.query(x, y).sum << endl;
    }
  }
  return 0;
}