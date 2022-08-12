#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
string a, b;
const int N = 2005;

int f[N][N];

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> a >> b;
  int m = a.size(), n = b.size();
  FOR(i, 1, m) {
    f[i][0] = i;
  }
  FOR(j, 1, n) {
    f[0][j] = j;
  }
  FOR(i, 1, m) {
    FOR(j, 1, n) {
      if(a[i-1] == b[j-1]) {
        f[i][j] = f[i-1][j-1];
      } else {
        f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1;
      }
    }
  }
  cout << f[m][n];
  return 0;
}
#endif