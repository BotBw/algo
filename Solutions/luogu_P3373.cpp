#include "bits/stdc++.h"

struct tag {
  modint sum, add, mul;
};

void push_up(tag& fa, const tag &l, const tag &r) {
  fa.sum = l.sum + r.sum;
}

void push_down(tag &fa, tag &l, int ll, tag &r, int lr) {
  modint add = fa.add, mul = fa.mul;
  fa.add = 0;
  fa.mul = 1;

  l.sum *= mul;
  l.sum += modint(ll) * add;
  l.mul *= mul;
  l.add *= mul;
  l.add += add;

  r.sum *= mul;
  r.sum += modint(lr) * add;
  r.mul *= mul;
  r.add *= mul;
  r.add += add;
}

tag ie() {
  return {0, 0, 1};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  modint::setmod(p);
  vector<tag> a(n + 1, ie());
  FOR(i, 1, n) cin >> a[i].sum;
  segtree<tag, push_up, push_down, ie> seg(1, n, a);
  FOR(i, 1, m) {
    int op;
    cin >> op;
    if(op == 1) {
      int x, y, k;
      cin >> x >> y >> k;
      if(x > y) swap(x, y);
      seg.update(x, y, [&](int l, int r, tag &x) {
        x.add *= k;
        x.mul *= k;
        x.sum *= k;
      });
    } else if (op == 2) {
      int x, y, k;
      cin >> x >> y >> k;
      if(x > y) swap(x, y);
      seg.update(x, y, [&](int l, int r, tag &x) {
        x.add += k;
        x.sum += (r - l + 1) * k;
      });
    } else {
      int x, y;
      cin >> x >> y;
      cout << seg.query(x, y).sum << '\n';
    }
  }
  return 0;
}