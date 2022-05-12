#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#ifdef LEET
#include "leet.h"
#else
/*
  gcd(a1, a2,...,an) = gcd(a1, a2-a1, a3-a2,...an-a_n-1)
*/

const int maxn = 5e5+10;
// const int maxn = 10;

ll a[maxn];

inline ll gcd(ll a, ll b) {
  return b ? gcd(b, a%b) : abs(a);
}

struct node {
  int l, r;
  ll sum, gcd;
} t[maxn*4];

void push_up(int i) {
  t[i].sum = t[i*2].sum + t[i*2+1].sum;
  t[i].gcd = gcd(t[i*2].gcd, t[i*2+1].gcd);
}

void build(int i, int l, int r) {
  t[i] = {l, r, 0, 0};
  if(l == r) {
    ll b = a[l] - a[l-1];
    t[i].gcd = t[i].sum = b;
    return;
  }
  int mi = (l+r)/2;
  build(i*2, l, mi);
  build(i*2+1, mi+1, r);
  push_up(i);
}

node query(int i, int l, int r) {
  if(l > r) return node{0,0,0,0};
  if(l <= t[i].l && t[i].r <= r) {
    return t[i];
  } else {
    int mi = (t[i].l + t[i].r)/2;
    if(r <= mi) {
      return query(i*2, l, r);
    } else if(mi < l) {
      return query(i*2+1, l, r);
    } else {
      auto left = query(i*2, l, r);
      auto right = query(i*2+1, l, r);
      node tmp;
      tmp.sum = left.sum + right.sum;
      tmp.gcd = gcd(left.gcd, right.gcd);
      return tmp;
    }
  }
}

void update(int i, int x, ll add) {
  if(t[i].l == t[i].r && t[i].l == x) {
    ll a = t[i].sum + add;
    t[i].sum = t[i].gcd = a;
    return;
  }
  int mi = (t[i].l + t[i].r)/2;
  if(x <= mi) update(i*2, x, add);
  else update(i*2+1, x, add);
  push_up(i);
}

int main() {
  int n, m;
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];

  build(1, 1, n);
  
  FOR(i, 1, m) {
    char c;
    ll c1,c2,c3;
    cin >> c;
    if(c == 'Q') {
      cin >> c1 >> c2;
      auto sum_node = query(1, 1, c1);
      auto gcd_node = query(1, c1 + 1, c2);
      cout << gcd(sum_node.sum, gcd_node.gcd) << endl;
    } else {
      cin >> c1 >> c2 >> c3;
      update(1, c1, c3);
      if(c2+1 <= n) update(1, c2+1, -c3);
    }
  }
  return 0;
}
#endif