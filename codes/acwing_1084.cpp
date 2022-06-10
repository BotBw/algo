#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 105;

int f[15][10][N];

int a, b, n;

int dp(int num) {
  if(num == 0) return 1;
  vector<int> dg;
  while(num) {
    dg.push_back(num % 10);
    num /= 10;
  }
  int ret = 0, last = 0;
  for(int i = dg.size() - 1; i >= 0; i--) {
    int x = dg[i];
    FOR(j, 0, x-1) {
      int mod = -last % n;
      mod += n;
      ret += f[i+1][j][mod];
    }
    last += x;
    if(i == 0 && last % n == 0) ret++; 
  }

  return ret;
}

#ifdef LEET
#include "leet.h"
#else
int main() {

  while(scanf("%d%d%d", &a, &b, &n) != -1) {

    memset(f, 0, sizeof f);

    for(int j = 0; j <= 9; j++) {
      f[1][j][j%n] = 1;
    }

    FOR(i, 2, 14) {
      FOR(j, 0, 9) {
        FOR(k, 0, n) {
          FOR(x, 0, 9) {
            int mod = (k - j) % n;
            if(mod < 0) mod += n;
            f[i][j][k] += f[i-1][x][mod];
          }
        }
      }
    }

    cout << dp(b) - dp(a-1) << endl;
  }
  return 0;
}
#endif