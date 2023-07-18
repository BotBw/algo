#include "bits/stdc++.h"

const int N = 1e4 + 5;

struct {
  int ch[26];
  int cnt;
} t[N * 50];

int fail[N * 50];
int idx;


void init() {
  idx = 0;
  memset(t, 0, sizeof t);
  memset(fail, 0, sizeof fail);
}

void insert(string s) {
  int p = 0;
  for(int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if(!t[p].ch[c]) t[p].ch[c] = ++idx;
    p = t[p].ch[c];
  }
  t[p].cnt++;
}

void build() {
  queue<int> q;

  FOR(i, 0, 25) {
    if(t[0].ch[i]) q.push(t[0].ch[i]);
  }
  while(q.size()) {
    int u = q.front();
    q.pop();
    FOR(c, 0, 25) {
      int &v = t[u].ch[c];
      if(!v) {
        v = t[fail[u]].ch[c];
        continue;
      }
      fail[v] = t[fail[u]].ch[c];
      q.push(v);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(_, 1, T) {
    init();
    int n;
    cin >> n;
    FOR(i, 1, n) {
      string word;
      cin >> word;
      insert(word);
    }
    build();
    string txt;
    cin >> txt;
    int p = 0;
    int ans = 0;
    for(int i = 0; i < txt.size(); i++) {
      int c = txt[i] - 'a';
      p = t[p].ch[c];
      int x = p;
      while(x) {
        ans += t[x].cnt;
        t[x].cnt = 0;
        x = fail[x];
      }
    }
    cout << ans << endl;
  }
  return 0;
}