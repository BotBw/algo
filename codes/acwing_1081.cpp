#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 35;

int c[N][N];
// c[i, j] = c[i-1, j-1] + c[i, j-1]
int x, y, k, b;


int dp(int num) {
  if(num == 0) return 0;
  vector<int> dgs;
  while(num) {
    dgs.push_back(num % b);
    num /= b;
  }
  int last = 0, ret = 0;
  int i;
  for(i = dgs.size() - 1; i >= 0; i--) {
    int x = dgs[i];
    if(x) {
      ret += c[k - last][i];
      if(x > 1) {
        if(k - last - 1 >= 0) ret += c[k - last - 1][i];
        break;
      } else {
        last++;
        if(last > k) break;
      }
    }
    if(i == 0 && last == k) ret ++;

  }
  return ret;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> x >> y >> k >> b;
  FOR(j, 0, N-1) {
    c[0][j] = 1;
  }
  FOR(i, 1, N-1) {
    FOR(j, i, N-1) {
      c[i][j] = c[i-1][j-1] + c[i][j-1];
    }
  }

  // FOR(i, 1, N-1) {
  //   FOR(j, 1, N-1) {
  //     cout << c[i][j] << "  ";
  //   }
  //   cout << endl;
  // }

  cout << dp(y) - dp(x-1);
  return 0;
}
#endif