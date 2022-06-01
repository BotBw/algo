#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int M = 10005;

int f[M];

int m, n;

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  f[0] = 1;
  FOR(i, 1, n) {
    int a;
    cin >> a;
    _FOR(j, m, a) {
      f[j] += f[j - a];
    }
  }
  // FOR(i, 1, n) cout << f[i] << ' ';
  // cout << endl;
  cout << f[m];
  return 0;
}
#endif