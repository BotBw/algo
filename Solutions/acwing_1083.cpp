#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 15;

int f[N][N]; 
// f[i, j]: i-digit number, the last digit is j
// f[i, j] = SUM(f[i-1, k]) (|k - j| >= 2)

int a, b;


int dp(int n) {
  if(n == 0) return 0;
  vector<int> dgs;
  while(n) {
    dgs.push_back(n % 10);
    n /= 10;
  }
  int ret = 0, last = -2;
  for(int i = dgs.size() - 1; i >= 0; i--) {
    int x = dgs[i];
    int j = (i == dgs.size() - 1);
    for(; j <= x-1; j++) {
      if(abs(j - last) >= 2) {
        ret += f[i+1][j];
      }
    }
    if(abs(x - last) < 2) break;
    last = x;
    if(i == 0) ret++;
  }
  for(int i = dgs.size() - 2; i >= 0; i--) {
    for(int j = 1; j <= 9; j++) {
      ret += f[i + 1][j];
    }
  }
  return ret;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> a >> b;

  FOR(j, 0, 9) {
    f[1][j] = 1;
  }

  FOR(i, 2, N-1) {
    FOR(j, 0, 9) {
      FOR(k, 0, 9) {
        if(abs(k - j) >= 2) {
          f[i][j] += f[i-1][k];
        }
      }
    }
  }

  // FOR(i, 1, N-1) {
  //   FOR(j, 0, 9) {
  //     cout << f[i][j] << "  ";
  //   }
  //   cout << endl;
  // }

  cout << dp(b) - dp(a-1);

  return 0;
}
#endif