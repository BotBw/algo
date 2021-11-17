#include <bits/stdc++.h>
using namespace std;

const int maxn = 105, maxm = 205, maxt = 205;

int f[maxm][maxt];
int n, M, T;

int main() {
  cin >> n >> M >> T;
  for (int i = 1; i <= n; i++) {
    int m_i, t_i;
    cin >> m_i >> t_i;
    for(int i = M; i >= m_i; i--) {
      for(int j = T; j >= t_i; j--) {
        f[i][j] = max(f[i][j], f[i-m_i][j-t_i] + 1);
      }
    }
  }
  cout << f[M][T];
  return 0;
}