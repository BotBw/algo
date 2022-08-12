#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)

const int N = 105, S = 100 * N;

struct st {
  int s, e, l;
  bool operator<(const st &b) const {
    return s * b.l < b.s * l;
  }
} st[N];

int f[N][S];
int n;
int main() {
  int T;
  cin >> T;
  FOR(t, 1, T) {
    cin >> n;
    int m = 0;
    FOR(i, 1, n) {
      cin >> st[i].s >> st[i].e >> st[i].l;
      m += st[i].s;
    }
    sort(st + 1, st + 1 + n);
    memset(f, 0xcf, sizeof f);
    int ans = 0;
    FOR(j, 0, m) f[0][j] = 0;
    FOR(i, 1, n) {
      FOR(j, 0, m) {
        if(j < st[i].s) f[i][j] = f[i-1][j];
        else f[i][j] = max(f[i-1][j], f[i-1][j-st[i].s] + max(0, st[i].e - (j - st[i].s) * st[i].l));
        if(i == n) ans = max(ans, f[i][j]);
      }
    }
    printf("Case #%d: %d\n", t, ans);
  }
}