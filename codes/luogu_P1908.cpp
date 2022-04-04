#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxn = 5e5+5;
int n;
const int NODE_N = maxn*4;

ll arr[maxn];
ll arr_cpy[maxn];
ll rnk[maxn];

struct node {
  ll val;
  int l, r;
  int lazy;
} tree[NODE_N];

void build(int i, int l, int r) {
  if (l == r) {
    tree[i].val = 0;
    tree[i].l = tree[i].r = l;
    return;
  }
  int mi = (r - l) / 2 + l;
  build(i * 2, l, mi);
  build(i * 2 + 1, mi + 1, r);
  tree[i].val = tree[i * 2].val + tree[i * 2 + 1].val;
  tree[i].l = l;
  tree[i].r = r;
  tree[i].lazy = 0;
}

void push_down(int i) {
  tree[i * 2].lazy += tree[i].lazy;
  tree[i * 2].val += tree[i].lazy * (tree[i * 2].r - tree[i * 2].l + 1);
  tree[i * 2 + 1].lazy += tree[i].lazy;
  tree[i * 2 + 1].val +=
      tree[i].lazy * (tree[i * 2 + 1].r - tree[i * 2 + 1].l + 1);
  tree[i].lazy = 0;
}

void update(int i, int l, int rr, int delta) {
  if (l <= tree[i].l && tree[i].r <= rr) {
    tree[i].val += delta * (tree[i].r - tree[i].l + 1);
    tree[i].lazy += delta;
    return;
  }
  if (tree[i].l != tree[i].r) push_down(i);
  int mi = (tree[i].l + tree[i].r)/2;
  if(l <= mi) update(i*2, l, rr, delta);
  if(mi + 1 <= rr) update(i*2+1, l, rr, delta);
  tree[i].val = tree[i*2].val + tree[i*2+1].val;
}

ll query(int i, int l, int rr) {
  if(l <= tree[i].l && tree[i].r <= rr) return tree[i].val;
  if(tree[i].l != tree[i].r) push_down(i);
  ll ans = 0, mi = (tree[i].l + tree[i].r)/2;
  if(l <= mi) ans += query(i*2, l, rr);
  if(mi + 1 <= rr) ans += query(i*2+1, l, rr);
  return ans;
}


#ifdef LEET
#include "leet.h"
#else
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  FOR(i, 1, n) {
    cin >> arr[i];
    arr_cpy[i] = arr[i];
  }
  sort(arr + 1, arr + n + 1);
  int len = distance(arr + 1, unique(arr + 1, arr + n + 1));
  FOR(i, 1, n) rnk[i] = distance(arr + 1, lower_bound(arr + 1, arr + len + 1, arr_cpy[i])) + 1;
  ll ans = 0;
  build(1, 1, len);
  FOR(i, 1, n) {
    ans += query(1, rnk[i]+1, len);
    update(1, rnk[i], rnk[i], 1);
  }
  cout << ans;
  return 0;
}
#endif