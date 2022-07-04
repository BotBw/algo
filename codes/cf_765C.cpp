#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)

typedef long long LL;
const int N = 505;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL pos[N], spd[N];
LL f[N][N][2];
int main() {
  LL n, l, k;
  LL res = INF;
  cin >> n >> l >> k;
  FOR(i, 1, n) cin >> pos[i];
  FOR(i, 1, n) cin >> spd[i];
  pos[n + 1] = l;
  memset(f, 0x3f, sizeof f);
  FOR(j, 0, k) {
    f[1][0][1] = 0;
  }
  FOR(i, 2, n + 1) {
    FOR(j, 0, k) {
      LL minf0 = INF, minf1 = INF;
      FOR(k, 1, i-1) {
        // if(k == 1) printf("%d %d %d\n", k, j, 0);
        LL dis = spd[k] * (pos[i] - pos[k]);
        if(j - i + k >= 0) minf0 = min(minf0, f[k][j - (i - k)][1] + dis);
        if(j - i + k + 1 >= 0 )minf1 = min(minf1, f[k][j - (i - k) + 1][1] + dis);
      }
      f[i][j][0] = minf0;
      f[i][j][1] = minf1;
      // printf("%lld ", f[i][j][1]);
    }
    // puts("");
  } 
  FOR(j, 0, min(n, k)) {
    res = min(res, f[n+1][j][1]);
  }
  printf("%lld\n", res);
  return 0;
}