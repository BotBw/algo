#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 1005, M = 505;

int f[N][M];

int n, m, k;


#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m >> k;
  FOR(i, 1, k) {
    int a, b;
    cin >> a >> b;
    _FOR(j, n, a) {
      _FOR(k, m, b + 1) {
        f[j][k] = max(f[j][k], f[j-a][k-b] + 1);
      }
    }
  }
  // FOR(i, 1, n) {
  //   FOR(j, 1, m) {
  //     cout << f[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  int c = f[n][m];
  int r = m;
  while(r > 0 && f[n][r] == c) r--;
  cout << c << ' ' << m - r;
  return 0;
}
#endif