#ifndef TREAP_H
#define TREAP_H

#include <stdlib.h>

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a, b) ((a) > (b) ? (b) : (a))
#endif

struct node {
  int key, val, l, r, sz, cnt;
};

struct Treap {
  static const int INF = 0x3f3f3f3f;
  node *t;
  int cnt;
  int root;
  Treap(int n) : t(new node[n + 1]), cnt(0) {
    get_node(-INF);
    get_node(INF);
    root = 1;
    t[1].r = 2;
    push_up(root);
    if (t[1].val < t[2].val) {
      zag(root);
    }
  }

  ~Treap() { delete[] t; }
  void insert(int key) { insert(root, key); }
  void remove(int key) { remove(root, key); }
  int get_rank(int key) const { return get_rank(root, key); }
  int get_key(int rank) const { return get_key(root, rank); }
  int get_next(int key) const { return get_next(root, key); }
  int get_prev(int key) const { return get_prev(root, key); }

 private:
  void insert(int &x, int key) {
    if (!x) {
      x = get_node(key);
      return;
    }
    if (t[x].key == key) {
      t[x].cnt++;
    } else if (key < t[x].key) {
      insert(t[x].l, key);
      if (t[t[x].l].val > t[x].val) zig(x);
    } else {
      insert(t[x].r, key);
      if (t[x].val < t[t[x].r].val) zag(x);
    }
    push_up(x);
  }

  void remove(int &x, int key) {
    if (!x) {
      return;
    }
    if (t[x].key == key) {
      if (t[x].cnt > 1) {
        t[x].cnt--;
      } else {
        if (t[x].l || t[x].r) {
          if (!t[x].r || t[t[x].l].val > t[t[x].r].val) {
            zig(x);
            remove(t[x].r, key);
          } else {
            zag(x);
            remove(t[x].l, key);
          }
        } else {
          x = 0;
        }
      }
    } else if (key < t[x].key) {
      remove(t[x].l, key);
    } else {
      remove(t[x].r, key);
    }
    push_up(x);
  }

  int get_rank(int x, int key) const {
    if (!x) return 0;
    if (key == t[x].key) {
      return t[t[x].l].sz + 1;
    } else if (key < t[x].key) {
      return get_rank(t[x].l, key);
    } else {
      return t[t[x].l].sz + t[x].cnt + get_rank(t[x].r, key);
    }
  }

  int get_key(int x, int rnk) const {
    if (!x) return INF;
    if (rnk <= t[t[x].l].sz) {
      return get_key(t[x].l, rnk);
    } else if (rnk <= t[t[x].l].sz + t[x].cnt) {
      return t[x].key;
    } else {
      return get_key(t[x].r, rnk - t[x].cnt - t[t[x].l].sz);
    }
  }

  int get_next(int x, int key) const {
    if (!x) return INF;
    if (t[x].key <= key) {
      return get_next(t[x].r, key);
    } else {
      return min(t[x].key, get_next(t[x].l, key));
    }
  }

  int get_prev(int x, int key) const {
    if (!x) return -INF;
    if (key <= t[x].key) {
      return get_prev(t[x].l, key);
    } else {
      return max(t[x].key, get_prev(t[x].r, key));
    }
  }

  int get_node(int key) {
    t[++cnt].key = key;
    t[cnt].val = rand();
    t[cnt].sz = t[cnt].cnt = 1;
    return cnt;
  }
  void push_up(int i) { t[i].sz = t[t[i].l].sz + t[t[i].r].sz + t[i].cnt; }
  void zig(int &x) {
    int l = t[x].l;
    t[x].l = t[l].r;
    t[l].r = x;
    x = l;
    push_up(t[x].r);
    push_up(x);
  }
  void zag(int &x) {
    int r = t[x].r;
    t[x].r = t[r].l;
    t[r].l = x;
    x = r;
    push_up(t[x].l);
    push_up(x);
  }
};

#endif