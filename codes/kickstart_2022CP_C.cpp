#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

char txt[N];

int cnt[26][N];

int n, q;

void init() {
  for(int i = 1; i <= n; i++) {
    for(int ch = 0; ch < 26; ch++) {
      cnt[ch][i] = cnt[ch][i-1];
      cnt[ch][i] += (ch + 'A' == txt[i]);
    }
  }
}

bool query(int l, int r) {
  bool flag = true;
  for(int c = 0; c < 26; c++) {
    int count = cnt[c][r] - cnt[c][l-1];
    if(count % 2 == 1) {
      if(!flag) {
        return false;
      }
      flag = false;
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  int t = 0;
  while(T--) {
    t++;
    scanf("%d%d", &n, &q);
    scanf("%s", txt + 1);
    init();
    int res = 0;
    for(int i = 0; i < q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      res += query(l, r);
    }
    printf("Case #%d: %d\n", t, res);
  }
  return 0;
}