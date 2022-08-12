#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 35;

int a[N];

int n;

LL f[N][N];
int pre[N][N];

void print(int i, int j) {
  int k = pre[i][j];
  if(k == 0) return;
  cout << k << " ";
  print(i, k - 1);
  print(k + 1, j);
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i];
    f[i][i] = a[i];
    pre[i][i] = i;
  }
  FOR(l, 2, n) {
    for(int i = 1; i + l - 1 <= n; i++) {
      int j = i + l - 1;
      int x = f[i+1][j] + a[i], y = f[i][j-1] + a[j];
      if(x > y) {
        f[i][j] = x;
        pre[i][j] = i;
      } else {
        f[i][j] = y;
        pre[i][j] = j;
      }
      for(int k = i + 1; k < j; k++) {
        int xx = f[i][k-1]*f[k+1][j] + a[k];
        if(f[i][j] < xx) {
          f[i][j] = xx;
          pre[i][j] = k;
        }
      }
    }
  }
  cout << f[1][n] << endl;
  print(1, n);
  return 0;
}
#endif