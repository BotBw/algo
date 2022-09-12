#include "bits/stdc++.h"

const int N = 250005;
int a[105];
bool f[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(_, 1, T) {
    int n;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    sort(begin(a) + 1, a + n + 1);
    int len = unique(begin(a) + 1, a + 1 + n) - a - 1;
    memset(f, 0, sizeof f);    
    f[0] = true;
    int res = 0;
    FOR(i, 1, len) {
      if(f[a[i]]) continue;
      debug(i, a[i]);
      res++;
      FOR(j, a[i], a[len]) {
        f[j] = f[j] || f[j - a[i]];
      }
      bool ok = true;
      FOR(i, 1, len) {
        if(!f[a[i]]) {
          ok = false;
          break;
        }
      }
      if(ok) {
        cout << res << endl;
        goto next_t;
      }
    }
    next_t:
      continue;
  }
  return 0;
}