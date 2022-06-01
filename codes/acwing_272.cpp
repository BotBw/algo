#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 3005;

int a[N], b[N], f[N][N];

int k[N];

int n;
#ifdef LEET
#include "leet.h"
#else
int main() {
  scanf("%d", &n);
  int *p = a;
  FOR(i, 1, 2) {
    FOR(j, 1, n) {
      scanf("%d", p + j);
    }
    p = b;
  }

  FOR(j, 1, n) {
    int maxf = 1;
    FOR(i, 1, n) {
      if(a[i] < b[j]) {
        maxf = max(maxf, f[i][j-1] + 1);
      }
      if(a[i] == b[j]) {
        // f[i][j] = 1;
        // FOR(k, 1, i-1) {
        //   if(a[k] < b[i]) {
        //     f[i][j] = max(f[k][j-1] + 1, f[i][j]);
        //   }
        // }
        f[i][j] = maxf;
      } else {
        f[i][j] = f[i][j-1];
      }
    }
  }
  int ans = 0;
  FOR(i, 1, n) {
    ans = max(ans, f[i][n]);
  }

  cout << ans;
  return 0;
}
#endif