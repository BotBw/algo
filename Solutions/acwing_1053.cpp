#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, ncnt, f[1005][N*21];

struct node {
  int ch[4];
  bool bad;
  int fail;
} t[N * 21];

char key[4] = {'A', 'G', 'C', 'T'};

int getCh(char c) {
  if(c == 'A') return 0;
  if(c == 'G') return 1;
  if(c == 'C') return 2;
  if(c == 'T') return 3;
  assert(false);
  return -1;
}

void insert(const char *str) {
  int u = 0;
  for(int i = 0; str[i]; i++) {
    int c = getCh(str[i]);
    if(!t[u].ch[c]) t[u].ch[c] = ++ncnt;
    u = t[u].ch[c];
  }
  t[u].bad = true;
}

void buildAC() {
  queue<int> q;
  for(int i = 0; i < 4; i++)
    if(t[0].ch[i]) q.push(t[0].ch[i]);

  while(q.size()) {
    int u = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int &v = t[u].ch[i], fail = t[u].fail;
      if(!v) {
        v = t[fail].ch[i];
      } else {
        t[v].fail = t[fail].ch[i];
        t[v].bad |= t[t[fail].ch[i]].bad;
        q.push(v);
      }
    }
  }
}

char seq[25];

char txt[1005];

int main() {
  int cases = 0;
  while(scanf("%d", &n) && n) {
    cases++;
    ncnt = 0;
    memset(t, 0, sizeof t);
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= n; i++) {
      scanf("%s", seq);
      insert(seq);
    }
    buildAC();
    scanf("%s", txt + 1);
    int len = strlen(txt + 1);
    f[0][0] = 0;
    int ans = 0x3f3f3f3f;
    for(int i = 0; i <= len; i++) {
      for(int j = 0; j <= ncnt; j++) {
        if(i == len) {
          ans = min(ans, f[i][j]);
          continue;
        }
        for(int k = 0; k < 4; k++) {
          int inc = key[k] != txt[i + 1];
          int st = t[j].ch[k];
          if(!t[st].bad) f[i+1][st] = min(f[i+1][st], f[i][j] + inc);
        //   bool tran = true;
        //   int p = st;
        //   while(p) {
        //     if(t[p].bad) {
        //       tran = false;
        //       break;
        //     }
        //     p = t[p].fail;
        //   }
        //   if(tran) f[i + 1][st] = min(f[i + 1][st], f[i][j] + inc);
        // }
        }
      }
    }
    if(ans == 0x3f3f3f3f) ans = -1;
    printf("Case %d: %d\n", cases, ans);
  }
  return 0;
}