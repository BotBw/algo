#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

int N, V, M;

const int maxv = 105, maxm = 105;

int f[maxv][maxm];


int main() {
  ios::sync_with_stdio(0);
  cin >> N >> V >> M;

  FOR(i, 1, N) {
    int v_i, m_i, w_i;
    cin >> v_i >> m_i >> w_i;

    _FOR(v, V, v_i) {
      _FOR(m, M, m_i) {
        f[v][m] = max(f[v][m], f[v-v_i][m-m_i] + w_i);
      }
    }
  }
  cout << f[V][M];
  return 0;
}