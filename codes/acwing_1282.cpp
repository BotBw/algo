#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#endif
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, M = 51;

struct node {
  int cnt;
  int ch[26];
  int fail;
} t[N * M];

int ncnt;

void insert(string str) {
  int p = 0;
  for(int i = 0; i < str.size(); i++) {
    int c = str[i] - 'a';
    if(!t[p].ch[c]) t[p].ch[c] = ++ncnt;
    p = t[p].ch[c];
  }
  t[p].cnt++;
}

void build() {
  queue<int> q;
  for(int i = 0; i < 26; i++)
    if(t[0].ch[i]) q.push(t[0].ch[i]);

  while(q.size()) {
    int u = q.front();
    q.pop();
    for(int i = 0; i < 26; i++) {
      int &v = t[u].ch[i], &fail = t[u].fail;
      if(!v) v = t[fail].ch[i];
      else {
        t[v].fail = t[fail].ch[i];
        q.push(v);
      } 
    }
  }
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    ncnt = 0;
    memset(t, 0, sizeof t);
    int n;
    cin >> n;
    while(n--) {
      string w;
      cin >> w;
      insert(w);
    }
    build();
    string text;
    cin >> text;
    int ans = 0;
    for(int i = 0, j = 0; i < text.size(); i++) {
      int c = text[i] - 'a';
      j = t[j].ch[c];
      int p = j;
      while(p) {
        ans += t[p].cnt;
        t[p].cnt = 0;
        p = t[p].fail;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
