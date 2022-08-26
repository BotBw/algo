#ifndef SEGTREE_H
#define SEGTREE_H

#include <vector>

#define lc(x) ((x) * 2)
#define rc(x) ((x) * 2 + 1)
#define len(x) (t[(x)].r - t[(x)].l + 1)

template <typename tag, void(*push_up)(tag&, const tag&, const tag&), void(*push_down)(tag&, tag&, int, tag&, int), tag(*ie)()>
class segtree {
  struct node {
    int l, r;
    tag val;
  };

  int lo, hi;
  std::vector<node> t;

  void build(int x, int l, int r, const vector<tag> &init) {
    t[x] = {l, r, ie()};
    if(l == r) {
      t[x] = {l, r, init[l]};
      return;
    }
    int mi = (l + r) / 2;
    build(lc(x), l, mi, init);
    build(rc(x), mi + 1, r, init);
    push_up(t[x].val, t[lc(x)].val, t[rc(x)].val);
  }

  void build(int x, int l, int r, const tag* init) {
    t[x] = {l, r, ie()};
    if(l == r) {
      t[x] = {l, r, init[l]};
      return;
    }
    int mi = (l + r) / 2;
    build(lc(x), l, mi, init);
    build(rc(x), mi + 1, r, init);
    push_up(t[x].val, t[lc(x)].val, t[rc(x)].val);
  }
  
  void _update(int x, int l, int r, void(*modifier)(int len, tag &)) {
    if(l <= t[x].l && t[x].r <= r) {
      modifier(len(x), t[x].val);
      return;
    }
    push_down(t[x].val, t[lc(x)].val, len(lc(x)), t[rc(x)].val, len(rc(x)));
    int mi = (t[x].l + t[x].r) / 2;
    if(l <= mi) _update(lc(x), l, r, modifier);
    if(r >= mi + 1) _update(rc(x), l, r, modifier);
    push_up(t[x].val, t[lc(x)].val, t[rc(x)].val);
  }

  tag _query(int x, int l, int r) {
    if(l <= t[x].l && t[x].r <= r) return t[x].val;
    push_down(t[x].val, t[lc(x)].val, len(lc(x)), t[rc(x)].val, len(rc(x)));
    int mi = (t[x].l + t[x].r) / 2;
    if(l <= mi && r >= mi + 1) {
      tag L = _query(lc(x), l, r);
      tag R = _query(rc(x), l, r);
      tag ret;
      push_up(ret, L, R);
      return ret;
    } else if(l <= mi) return _query(lc(x), l, r);
    else return _query(rc(x), l, r);
  }


 public:
  segtree(int _lo, int _hi): lo(_lo), hi(_hi) {
    int n = hi - lo + 1;
    vector<tag> init(n + 1, ie());
    t = vector<node>(4*n);
    build(1, lo, hi, init);
  }

  segtree(int _lo, int _hi, const vector<tag> &init): lo(_lo), hi(_hi) {
    int n = hi - lo + 1;
    t = vector<node>(4*n);
    build(1, lo, hi, init);
  }

  segtree(int _lo, int _hi, const tag *init): lo(_lo), hi(_hi) {
    int n = hi - lo + 1;
    t = vector<node>(4*n);
    build(1, lo, hi, init);
  }

  void update(int x, void(*modifier)(int len, tag &)) {
    assert(lo <= x && x <= hi);
    _update(1, x, x, modifier);
  }

  void update(int l, int r, void(*modifier)(int len, tag &)) {
    assert(l <= r && lo <= l && r <= hi);
    _update(1, l, r, modifier);
  }

  tag query(int x) {
    assert(lo <= x && x <= hi);
    return _query(1, x, x);
  }

  tag query(int l, int r) {
    assert(l <= r && lo <= l && r <= hi);
    return _query(1, l, r);
  }
};

#undef lc
#undef rc
#undef len

#endif