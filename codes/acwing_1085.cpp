#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 15;

int f[N][10];

int n, m;


int dp(int num) {
  if(num == 0) return 1;

  vector<int> dg;

  while(num) {
    dg.push_back(num % 10);
    num /= 10;
  }
  int ret = 0, last = 0;
  for(int i = dg.size()-1; i >= 0; i--) {
    int x = dg[i];
    FOR(j, 0, x-1) {
      if(j == 4) continue;
      if(last == 6 && j == 2) continue;
      ret += f[i+1][j];
    }
    if(x == 4) break;
    if(x == 2 && last == 6) break;
    last = x;
    if(i == 0) ret++;
  }
  return ret;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  FOR(j, 0, 9) {
    if(j == 4) continue;
    f[1][j] = 1;
  }

  FOR(i, 2, N-1) {
    FOR(j, 0, 9) {
      if(j == 4) continue;
      FOR(k, 0, 9) {
        if(j == 6 && k == 2) continue;
        f[i][j] += f[i-1][k];
      }
    }
  }

  while(cin >> n >> m) {
    if(n == 0 && m == 0) break;
    cout << dp(m) - dp(n-1) << endl;
  }
  return 0;
}
#endif