#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 1e5 + 10;
int n, a[N];
#ifdef LEET
#include "leet.h"
#else
int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    FOR(i ,1 ,n) cin >> a[i];
    FOR(i, 2, n) {
      a[i] = max(a[i - 1], a[i - 2] + a[i]);
    }

    cout << a[n] << endl;
  }
  return 0;
}
#endif