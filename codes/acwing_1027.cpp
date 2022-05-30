#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 11;

int f[N][N][N][N];

int g[N][N];

int dx1[] = {-1, -1, 0, 0};
int dy1[] = {0, 0, -1, -1};
int dx2[] = {-1, 0, -1, 0};
int dy2[] = {0, -1, 0, -1};

int n;
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n;

  int a, b, c;
  while(cin >> a >> b >> c && !(!a && !b && !c)) {
    g[a][b] = max(g[a][b], c);
  }

  FOR(x1, 1, n) {
    FOR(y1, 1, n) {
      FOR(x2, 1, n) {
        FOR(y2, 1, n) {
          int maxx = 0;
          FOR(k, 0, 3) {
            int xx1 = x1 + dx1[k], xx2 = x2 + dx2[k], yy1 = y1 + dy1[k], yy2 = y2 + dy2[k];
            if(x1 == x2 && y1 == y2) {
              maxx = max(maxx, f[xx1][yy1][xx2][yy2] + g[x1][y1]);
            } else {
              maxx = max(maxx, f[xx1][yy1][xx2][yy2] + g[x1][y1] + g[x2][y2]);
            }
          }
          f[x1][y1][x2][y2] = maxx;
        }
      }
    }
  }
  // FOR(i, 1, n) {
  //   FOR(j, 1, n) {
  //     cout << g[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << f[n][n][n][n];
  return 0;
}
#endif