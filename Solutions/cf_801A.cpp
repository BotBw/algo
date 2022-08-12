#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)

const int N = 45, M = 45;
int g[N][M];
int n, m;
int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    FOR(i, 1, n) {
      FOR(j, 1, m) {
        cin >> g[i][j];
      }
    }
    int res = INT_MAX;
    FOR(a, 1, n) {
      FOR(b, 1, m) {
        int st = INT_MIN;
        int flag = true;
        FOR(i, 1, n - a + 1) {
          FOR(j, 1, m - b + 1) {
            int maxV = INT_MIN;
            FOR(ii, i, i + a - 1) {
              FOR(jj, j, j + b - 1) {
                if(maxV < g[ii][jj]) {
                  maxV = g[ii][jj];
                }
              }
            }
            if(maxV != st) {
              if(st == INT_MIN) st = maxV;
              else {
                flag = false;
                break;
              }
            }
          }
          if(!flag) break;
        }
        if(flag) {
          res = min(res, a * b);
        } 
      }
    }
    printf("%d\n", res);
  }
  return 0;
}