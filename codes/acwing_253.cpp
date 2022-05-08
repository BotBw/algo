#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for (int i = (a); i >= (b); --i)

const int maxn = 1e5 + 5;
// const int maxn = 10;

const int INF = 1e8;

struct node {
  int key, val, l, r, cnt, sz;
} t[maxn];

int cnt, root;

void pushup(int i) { t[i].sz = t[t[i].l].sz + t[t[i].r].sz + t[i].cnt; }

int getNode(int key) {
  t[++cnt].key = key;
  t[cnt].val = rand();
  t[cnt].cnt = t[cnt].sz = 1;
  return cnt;
}

void zig(int &x) {
  int l_t = t[x].l;
  t[x].l = t[l_t].r;
  t[l_t].r = x;
  x = l_t;
  pushup(t[x].r);
  pushup(x);
}

void zag(int &x) {
  int r_t = t[x].r;
  t[x].r = t[r_t].l;
  t[r_t].l = x;
  x = r_t;
  pushup(t[x].l);
  pushup(x);
}

void insert(int &p, int key) {
  if (!p) {
    p = getNode(key);
    return;
  }
  if (t[p].key == key)
    t[p].cnt++;
  else if (key < t[p].key) {
    insert(t[p].l, key);
    if (t[p].val < t[t[p].l].val) zig(p);
  } else {
    insert(t[p].r, key);
    if (t[p].val < t[t[p].r].val) zag(p);
  }

  pushup(p);
}

void remove(int &i, int key) {
  if (!i) return;
  if (t[i].key == key) {
    if (t[i].cnt > 1)
      t[i].cnt--;
    else {
      if (t[i].l || t[i].r) {
        if (!t[i].r || t[t[i].l].val > t[t[i].r].val) {
          zig(i);
          remove(t[i].r, key);
        } else {
          zag(i);
          remove(t[i].l, key);
        }
      } else
        i = 0;
    }
  } else if (key < t[i].key)
    remove(t[i].l, key);
  else
    remove(t[i].r, key);
  pushup(i);
}

int get_rank_by_key(int rt, int key) {
  if (!rt) return -1;
  if (key == t[rt].key)
    return t[t[rt].l].sz + 1;
  else if (key < t[rt].key)
    return get_rank_by_key(t[rt].l, key);
  else
    return t[t[rt].l].sz + t[rt].cnt + get_rank_by_key(t[rt].r, key);
}

int get_key_by_rank(int rt, int rnk) {
  if (!rt) return INF;
  if (rnk <= t[t[rt].l].sz)
    return get_key_by_rank(t[rt].l, rnk);
  else if (rnk <= t[t[rt].l].sz + t[rt].cnt)
    return t[rt].key;
  else
    return get_key_by_rank(t[rt].r, rnk - t[rt].cnt - t[t[rt].l].sz);
}

int get_next(int rt, int key) {
  if (!rt) return INF;
  if (t[rt].key <= key)
    return get_next(t[rt].r, key);
  else
    return min(t[rt].key, get_next(t[rt].l, key));
}

int get_prev(int rt, int key) {
  if (!rt) return -INF;
  if (key <= t[rt].key)
    return get_prev(t[rt].l, key);
  else
    return max(t[rt].key, get_prev(t[rt].r, key));
}

void init() {
  getNode(-INF);
  getNode(INF);
  root = 1;
  t[1].r = 2;
  pushup(root);
  if (t[1].val < t[2].val) zag(root);
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  int n;
  cin >> n;
  init();
  FOR(i, 1, n) {
    int opt, x;
    cin >> opt >> x;
    switch (opt) {
      case 1:
        insert(root, x);
        break;
      case 2:
        remove(root, x);
        break;
      case 3:
        cout << get_rank_by_key(root, x) - 1 << endl;
        break;
      case 4:
        cout << get_key_by_rank(root, x + 1) << endl;
        break;
      case 5:
        cout << get_prev(root, x) << endl;
        break;
      case 6:
        cout << get_next(root, x) << endl;
        break;
      default:
        abort();
    }
  }
  return 0;
}
#endif