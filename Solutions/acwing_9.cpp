#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

int N, V;

const int maxn = 105, maxv = 105, maxs = 105;

int f[maxv];

int cost[maxs], val[maxs];

int main() {
  ios::sync_with_stdio(0);
  cin >> N >> V;

  FOR(i, 1, N) {
    int S_i;
    cin >> S_i;
    FOR(j, 1, S_i) cin >> cost[j] >> val[j];

    _FOR(j, V, 0) {
      FOR(k, 1, S_i) {
        if(cost[k] > j) continue;
        f[j] = max(f[j], f[j-cost[k]]+val[k]);
      }
    }
  }

  cout << f[V];
  return 0;
}