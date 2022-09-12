#include "bits/stdc++.h"

const int N = 1005, V = 20005;

ll f[V][2];
ll q[V];
int hh,tt;

struct item {
  int v, w, s;
} a[N];

int n, v;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> v;

  FOR(i, 1, n) {
    cin >> a[i].v >> a[i].w >> a[i].s;
  }

  FOR(i, 1, n) {
    // f[k * v + d] = max(f[(k-1)*v + d] - (k-1)*w, f[(k-2)*v + d] - (k-2)*w, ...) + k * w
    // = max(f[(k-1) * v + d] + w,  f
    // f[(k-1)*v + d] = max(f[(k-2)*v + d] -(k-2) * w, f[(k-3)*v + d) + 2*w, ...) + (k - 1) * w;
    // k * v + d <= V
    // k <= (a[i] - d) // v
    FOR(d, 0, a[i].v - 1) {
      tt = -1, hh = 0;
      FOR(k, 0, (v - d) / a[i].v) {
        while(hh <= tt && f[q[tt] * a[i].v + d][i - 1 & 1] - q[tt] * a[i].w <= f[k * a[i].v + d][i - 1 & 1] - k * a[i].w) tt--;
        q[++tt] = k;
        while(hh <= tt && k - q[hh] > a[i].s) hh++;
        f[k * a[i].v + d][i & 1] = f[q[hh] * a[i].v + d][i - 1 & 1] - (q[hh] * a[i].w) + k * a[i].w;
      }
    }
  }
  cout << f[v][n & 1];
  return 0;
}