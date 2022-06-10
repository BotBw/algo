#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 15;

int f[N][N];
// f[i][j], highest digit is i, j digits in total
// f[i][j] = sum(f[k][j-1]) k >= i;
int a, b;

int dp(int n) {
  if(n == 0) return 1;
  vector<int> dgs;
  while(n) {
    dgs.push_back(n % 10);
    n /= 10;
  }
  int last = 0, ret = 0;
  for(int i = dgs.size() - 1; i >= 0; i--) {
    int x = dgs[i];
    FOR(j, 0, x-1) {
      if(last <= j) {
        ret += f[j][i+1];
      }
    }
    if(last > x) break;
    last = x;
    if(i == 0) ret++;
  }
  return ret;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  FOR(i, 0, 9)
    f[i][1] = 1;

  FOR(j, 2, N-1) {
    FOR(i, 0, 9) {
      FOR(k, i, 9) {
        f[i][j] += f[k][j-1];
      }
    }
  }

  // FOR(i, 0, 9) {
  //   FOR(j, 1, N-1) {
  //     cout << f[i][j] << "  ";
  //   }
  //   cout << endl;
  // }
  while(scanf("%d%d", &a, &b) != -1) {
    cout << dp(b) - dp(a-1) << endl;
  }
  return 0;
}
#endif