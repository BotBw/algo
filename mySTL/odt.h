#ifndef ODT_H
#define ODT_H

#include <set>
#include <utility>

class odt {
  typedef long long ll;
  struct node {
    ll l, r;
    mutable ll val;
    bool operator<(const node &other) const {
      return l < other.l;
    }
  };
  std::set<node> t;

  auto split(int x) {
    auto it = t.lower_bound({x, x, 0});
    if(it != t.end() && it->l == x) return it;
    it--;
    ll l = it->l, r = it->r, val = it->val;
    t.erase(it);
    t.insert({l, x-1, val});
    return t.insert({x, r, val}).first;
  }

  public:
    odt(ll lo, ll hi, ll init) {
      t.insert({lo, hi, init});
    }

    void assign(ll l, ll r, ll val) {
      auto hi = split(r + 1), lo = split(l);
      t.erase(lo, hi);
      t.insert({l, r, val});
    }

    void add(ll l, ll r, ll val) {
      auto hi = split(r + 1), lo = split(l);
      for(auto it = lo; it != hi; it++)
        it->val += val;
    }
};

#endif
