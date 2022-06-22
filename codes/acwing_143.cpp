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

const int N = 1e5 + 10, M = 31 * N;

struct node {
  int son[2];
} t[M];

int ncnt;

void insert(int val) {
  int u = 0;
  _FOR(i, 30, 0) {
    int c = val >> i & 1;
    if(!t[u].son[c]) {
      t[u].son[c] = ++ncnt;
    }
    u = t[u].son[c];
  }
}

int query(int val) {
  int u = 0;
  int res = 0;
  _FOR(i, 30, 0) {
    int c = val >> i & 1;
    if(t[u].son[!c]) c = !c;
    res += c << i;
    u = t[u].son[c];
  }
  return res;
}

int a[N], ans, n;
int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) {
    if(i > 1) {
      int aa = query(a[i]);
      ans = max(ans, aa ^ a[i]);
    }
    insert(a[i]);
  }
  printf("%d", ans);
  return 0;
}
