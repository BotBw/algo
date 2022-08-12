#include <bits/stdc++.h>
using namespace std;

const int N = 205, L = 1e6 + 10;

struct node {
  int ch[26];
  int f;
  int fail;
} t[L];

int n, ncnt;
int q[L], hh, tt;
int id[N];
char w[L];

void insert(const char *str, int x) {
  int u = 0;
  for(int i = 0; str[i]; i++) {
    int ch = str[i] - 'a';
    int &v = t[u].ch[ch];
    if(!v) v = ++ncnt;
    u = v;
    t[u].f++;
  }
  id[x] = u;
}

void buildAC() {
  hh = 0; tt = -1;
  for(int i = 0; i < 26; i++)
    if(t[0].ch[i]) 
      q[++tt] = t[0].ch[i];

  while(hh <= tt) {
    int u = q[hh++];

    for(int ch = 0; ch < 26; ch++) {
      int &v = t[u].ch[ch], fail = t[u].fail;
      if(!v) v = t[fail].ch[ch];
      else {
        t[v].fail = t[fail].ch[ch];
        q[++tt] = v;
      }
    }
  }
}

int main() {
  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    scanf("%s", w);
    insert(w, i);
  }

  buildAC();

  for(int i = ncnt - 1; i >= 0; i--) {
    int u = q[i], v = t[u].fail;
    t[v].f += t[u].f;
  }
  for(int i = 1; i <= n; i++) {
    printf("%d\n", t[id[i]].f);
  }
  return 0;
}