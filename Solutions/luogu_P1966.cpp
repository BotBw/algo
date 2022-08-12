#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
// const int maxn = 1e5+10;
const int maxn = 100;

const int MOD = 1e8 - 3;


int n;
int mapping[maxn];

struct discrete {
  int val, id;
  bool operator<(const discrete &b) const {
    return val < b.val;
  }
} a[maxn], b[maxn];

int tree[maxn*4];
int lazy[maxn*4];

void push_down(int i, int tl, int tr) {
  if(tl == tr) return;
  int tmi = (tr + tl)/2;
  tree[i*2] += lazy[i] * (tmi - tl + 1);
  tree[i*2 + 1] += lazy[i] * (tr - tmi);
  lazy[i*2] += lazy[i];
  lazy[i*2 + 1] += lazy[i];
  lazy[i] = 0;
}

void update(int i, int tl, int tr, int l, int r) {
  if (l <= tl && tr <= r) {
    tree[i] += 1 * (tr - tl+1);
    lazy[i] += 1;
    return;
  }
  push_down(i, tl, tr);
  int tmi = (tl + tr)/2;
  if(l <= tmi) update(i*2, tl, tmi, l, r);
  if(r >= tmi+1) update(i*2+1, tmi+1, tr, l, r);
  tree[i] = tree[i*2] + tree[i*2+1];
}

int query(int i, int tl, int tr, int l, int r) {
  if(l <= tl && tr <= r) {
    return tree[i];
  }
  push_down(i, tl, tr);
  int ans = 0;
  int tmi = (tl + tr)/2;
  if(l <= tmi) ans += query(i*2, tl, tmi, l, r);
  if(r >= tmi+1) ans += query(i*2+1, tmi+1, tr, l, r);
  return ans;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i].val, a[i].id = i;
  FOR(i, 1, n) cin >> b[i].val, b[i].id = i;
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  FOR(i, 1, n) {
    mapping[b[i].id] = a[i].id;
  }
  int ans = 0;
  FOR(i, 1, n) {
    ans += query(1, 1, n, mapping[i] + 1, n);
    ans %= MOD;
    update(1, 1, n, mapping[i], mapping[i]);
  }
  cout << ans << endl;
  return 0;
}
#endif