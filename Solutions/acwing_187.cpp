#include "bits/stdc++.h"

const int N = 55;
int n;
int a[N];
int up[N], down[N];
int l1, l2;
bool dfs(int x, int cur) {
  if(l1 + l2 > x) return false;
  if(cur == n + 1) return true;
  // up
  if(l1 == 0 || up[l1] < a[cur]) {
    up[++l1] = a[cur];
    if(dfs(x, cur + 1)) return true;
    l1--;
  } else {
    int l = 1, r = l1;
    while(l < r) {
      int mi = (l + r) / 2;
      if(up[mi] >= a[cur]) r = mi;
      else l = mi + 1;
    }
    int val = up[l];
    up[l] = a[cur];
    if(dfs(x, cur + 1)) return true;
    up[l] = val;
  }

  if(l2 == 0 || down[l2] > a[cur]) {
    down[++l2] = a[cur];
    if(dfs(x, cur + 1)) return true;
    l2--;
  } else {
    int l = 1, r = l2;
    while(l < r) {
      int mi = (l + r) / 2;
      if(down[mi] <= a[cur]) r = mi;
      else l = mi + 1;
    }
    int val = down[l];
    down[l] = a[cur];
    if(dfs(x, cur + 1)) return true;
    down[l] = val;
  }
  return false;
}

bool check(int x) {
  l1 = l2 = 0;
  return dfs(x, 1);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  while(cin >> n && n) {
    FOR(i, 1, n) cin >> a[i];
    int l = 1, r = n;
    while(l < r) {
      int mi = (l + r) / 2;
      if(check(mi)) r = mi;
      else l = mi + 1;
    }
    cout << l << '\n';
  }
  return 0;
}