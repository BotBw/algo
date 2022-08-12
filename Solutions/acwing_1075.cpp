#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
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

const int N = 5e4 + 10;

int n;

struct edge {
  int v, w, next;
} e[N];

int head[N], cnt, ans;
bool notRoot[N];

void add(int a, int b, int c) {
  e[++cnt] = {b, c, head[a]};
  head[a] = cnt;
}

int dfs(int u) {
  int d1, d2;
  d1 = d2 = 0;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].v, w = e[i].w;
    int d = dfs(v) + w;
    if(d > d1) {
      d2 = d1;
      d1 = d;
    } else if(d > d2) {
      d2 = d;
    }
  }
  ans = max(ans, d1 + d2);
  return d1;
}

int main() {
  cin >> n;

  for(int i = 1; i <= n; i++) {
    int sum = 1;
    for(int j = 2; j <= i/j; j++) {
      if(i % j == 0) {
        sum += j;
        if(j != i/j) {
          sum += i/j;
        }
      }
    }
    if(sum < i) {
      // printf("add %d %d\n", sum, i);
      add(sum, i, 1);
      notRoot[i] = true;
    }
  }

  FOR(i, 1, n) {
    if(!notRoot[i])
      dfs(i);
  }

  cout << ans;

  return 0;
}
