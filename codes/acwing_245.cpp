#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#endif

const int N = 500005;

int n, m;
int a[N];

struct node {
  int tl, tr;
  LL ans, begin, end, sum;
} t[N*4];

void push_up(node &fa, node &l, node &r) {
  fa.sum = (l.sum + r.sum);

  fa.ans = max(l.ans, r.ans);
  fa.ans = max(fa.ans, max(l.end + r.begin, max(l.sum, r.sum)));

  fa.begin = max(l.sum + r.begin, l.begin);
  fa.end = max(r.sum + l.end, r.end);
}

void push_up(int i) {
  push_up(t[i], t[i*2], t[i*2+1]);
}

void build(int i, int l, int r) {
  t[i].tl = l; t[i].tr = r;
  if(l == r) {
    t[i] = {l, r, a[l], a[l], a[l], a[l]};
    return;
  }
  int mi = (l + r) >> 1;
  build(i*2, l, mi);
  build(i*2+1, mi+1, r);
  push_up(i);
}

void update(int i, int x, int val) {
  if(t[i].tl == t[i].tr && t[i].tl == x) {
    t[i] = {x, x, val, val, val, val};
    return;
  }
  int mi = (t[i].tl + t[i].tr) >> 1;·
  if(x <= mi) update(i*2, x, val);
  else update(i*2+1, x, val);
  push_up(i);
}

node query(int i, int l, int r) {
  if(l <= t[i].tl && t[i].tr <= r) {
    return t[i];
  }
  int mi = (t[i].tl + t[i].tr) >> 1;
  bool bl = 0, br = 0;
  node fa{0}, ll{0}, rr{0};
  if(l <= mi) ll = query(i*2, l, r), bl = 1;
  if(r >= mi + 1) rr = query(i*2 + 1, l, r), br = 1;
  if(bl && br) push_up(fa, ll, rr);
  else if(bl) return ll;
  else if(br) return rr;
  return fa;
}



int main() {
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];
  build(1, 1, n);
  FOR(i, 1, m) {
    int k, x, y;
    cin >> k >> x >> y;
    if(k == 1) {
      if(x > y) swap(x, y);
      cout << query(1, x, y).ans << endl;
    } else {
      update(1, x, y);
    }
  }
  return 0;
}
