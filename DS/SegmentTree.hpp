#ifndef SEGMENTTREE_H
struct SegmentTree {
  using ll = long long;
  const int elementNum;
  const int *const arr;
  const int nodeNum;
  ll *t;
  ll *lazy;
  SegmentTree() = delete;
  SegmentTree(int n, int *_arr)
      : elementNum{n},
        arr(_arr),
        nodeNum{n * 4},
        t(new ll[n * 4]),
        lazy(new ll[n * 4]){build(1, 1, elementNum);}
  SegmentTree(const SegmentTree &) = delete;
  SegmentTree(const SegmentTree &&) = delete;
  ll query(int l, int r) { return query(l, r, 1, elementNum, 1); }
  void update(int l, int r, int x) { update(l, r, x, 1, elementNum, 1); }

 private:
  ll query(int l, int r, int tl, int tr, int i) {
    if (l <= tl && tr <= r) {
      return t[i];
    }
    push_down(i, tl, tr);
    int mi = (tl + tr) / 2;
    ll ans = 0;
    if (l <= mi) ans += query(l, r, tl, mi, i * 2);
    if (mi < r) ans += query(l, r, mi + 1, tr, i * 2 + 1);
    return ans;
  }
  void update(int l, int r, int x, int tl, int tr, int i) {
    if (l <= tl && tr <= r) {
      t[i] += (tr - tl + 1) * x;
      lazy[i] += x;
      return;
    }
    push_down(i, tl, tr);
    int mi = (tl + tr) / 2;
    if (l <= mi) update(l, r, x, tl, mi, i * 2);
    if (mi < r) update(l, r, x, mi + 1, tr, i * 2 + 1);
    t[i] = t[i * 2] + t[i * 2 + 1];
  }

  void build(int i, int l, int r) {
    if (l == r) {
      t[i] = arr[l];
      return;
    }
    int mi = (l + r) / 2;
    build(i * 2, l, mi);
    build(i * 2 + 1, mi + 1, r);
    lazy[i] = 0;
    t[i] = t[i * 2] + t[i * 2 + 1];
  }

  void push_down(int i, int tl, int tr) {
    if (tl == tr) return;
    if (lazy[i] == 0) return;
    int mi = (tl + tr) / 2;
    t[i * 2] += (mi - tl + 1) * lazy[i];
    t[i * 2 + 1] += (tr - mi) * lazy[i];
    lazy[i * 2] += lazy[i];
    lazy[i * 2 + 1] += lazy[i];
    lazy[i] = 0;
  }
};
#endif