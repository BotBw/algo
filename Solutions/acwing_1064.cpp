#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 15, K = N*N, S = 1 << 10;

vector<int> st;
int cnt[S];

LL f[2][K][S];

int n, k;

bool check(int state) {
  return !((state & state >> 1));
}

int cal(int state) {
  int ret = 0;
  for(int i = 0; i < n; i++) {
    if(state & (1 << i)) ret++;
  }
  return ret;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> k;
  for(int stt = 0; stt < 1 << n; stt++) {
    if(check(stt)) {
      st.push_back(stt);
      cnt[stt] = cal(stt);
    }
  }

  f[0][0][0] = 1;

  FOR(i, 1, n + 1) {
    FOR(j, 0, k) {
      for(int u = 0; u < st.size(); u++) {
        f[i & 1][j][u] = 0;
        int st_u = st[u];
        for(int v = 0; v < st.size(); v++) {
          int st_v = st[v];
          if((j - cnt[st_u] < 0) || (f[i-1 & 1][j - cnt[st_u]][v] == 0)) continue;
          if((st_v & st_u) || (st_v & (st_u << 1)) || (st_v & (st_u >> 1))) continue;
          // int c = cnt[st_u];
          // if(j >= c) {
            f[i & 1][j][u] += f[i-1 & 1][j-cnt[st_u]][v];
          // }
          // printf("%d %d %d %d %d\n", i, j, st_u, st_v, f[i&1][j][u]);
        }
      }
    }
  }

  cout << f[n + 1 & 1][k][0];

  return 0;
}
#endif