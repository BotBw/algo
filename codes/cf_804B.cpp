#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif
int mat[2][2] = {{1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n-1) {
      FOR(j, 0, m-1) {
        int x = i/2, y = j/2;
        if((x + y) & 1) {
          cout << (mat[i & 1][j & 1] ^ 1) << ' ';
        } else {
          cout << (mat[i & 1][j & 1]) << ' ';
        }
      }
      cout << '\n';
    }
  }
  return 0;
}