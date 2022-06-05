#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

vector<int> st;
const int N = 105, S = 1 << 10;
int row[N], cnt[S];
int n, m;

int f[2][S][S];

bool check(int state) {
  return !((state & state << 1) || (state & state >> 1) || (state & state << 2) || (state & state >> 2));
}

int cal(int state) {
  int ret = 0;
  for(int i = 0; i < m; i++) {
    if(state & (1 << i)) ret++;
  }
  return ret;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  FOR(i, 1, n) {
    int state = 0;
    FOR(j, 0, m - 1) {
      char c;
      cin >> c;
      if(c == 'H') state |= 1 << j;
    }
    row[i] = state;
  }
  FOR(stt, 0, (1 << m) - 1) {
    if(check(stt)) {
      st.push_back(stt);
      cnt[stt] = cal(stt);
    }
  }
  memset(f, -0x3f, sizeof f);
  f[0][0][0] = 0;

  FOR(i, 1, n + 2) {
    for(int j = 0; j < st.size(); j++) {
      if(st[j] & row[i]) continue;
      for(int k = 0; k < st.size(); k++) {
        if(st[j] & st[k]) continue;
        for(int u = 0; u < st.size(); u++) {
          if(st[j] & st[u]) continue;
          f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][k][u] + cnt[st[j]]);
        }
      }
    }
  }
  cout << f[n + 2 & 1][0][0] << endl;
  return 0;
}
#endif