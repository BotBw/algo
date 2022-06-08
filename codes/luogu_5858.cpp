#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 5005;

LL f[2][N], a[N];
int n, w, s;

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> w >> s;
  FOR(i ,1, n) cin >> a[i];

  memset(f, -0x3f, sizeof f);

  f[0][0] = 0;

  FOR(i, 1, n) {
    deque<int> ks;
    ks.push_back(min(i, w));
    _FOR(j, min(i, w), 1) {
      while(ks.size() && f[i-1 & 1][ks.back()] <= f[i-1 & 1][j-1]) ks.pop_back();
      ks.push_back(j-1);
      while(ks.front() - j + 1 > s) ks.pop_front();
      f[i & 1][j] = f[i-1 & 1][ks.front()] + j * a[i];

      // printf("%d %d %lld from %d %d %lld\n", i, j, f[i][j], i-1, ks.front(), f[i-1][ks.front()]);

      // int cur = j * a[i];
      // FOR(k, j-1, min(j+s-1, w)) {
      //   f[i][j] = max(f[i][j], f[i-1][k]);
      // }
      // f[i][j] += cur;
    }
  }

  LL ans = -0x3f3f3f3f3f3f3f3f;
  FOR(i, 1, w) {
    ans = max(ans, f[n & 1][i]);
  }
  cout << ans;
  return 0;
}
#endif