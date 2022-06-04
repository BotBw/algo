#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int V = 1005, MOD = 1e9+7;

int f[V], cnt[V];
int n, v;
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> v;
  FOR(i, 0, v) cnt[i] = 1;
  FOR(i, 1, n) {
    int a, b;
    cin >> a >> b;
    _FOR(j, v, a) {
      if(f[j] < f[j-a] + b) {
        f[j] = f[j-a] + b;
        cnt[j] = cnt[j-a];
      } else if(f[j] == f[j-a] + b) {
        cnt[j] += cnt[j-a];
        cnt[j] %= MOD;
      }
    }
  }
  cout << cnt[v];
  return 0;
}
#endif