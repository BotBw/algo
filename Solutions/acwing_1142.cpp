#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 305, M = 8005;

struct edge {
  int u, v, w;
  bool operator<(const edge &b) const {
    return w < b.w;
  }
} e[M];

int cnt;

int n, m;

int fa[N];

void init() {
  FOR(i, 1, n) fa[i] = i;
}

int find(int x) {
  return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int l, r;

bool check(int l){
  int ans = 0;
  init();
  FOR(i ,1 ,cnt) {
    if(e[i].w > l) continue;
    int x = find(e[i].u), y = find(e[i].v);
    if(x != y) {
      fa[y] = x;
      ans++;
      if(ans == n - 1) return true;
    }
  }
  return false;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  FOR(i, 1, m) {
    int u, v, c;
    cin >> u >> v >> c;
    e[++cnt] = {u, v, c};
    r = max(r, c);
  }
  while(l < r) {
    int mi = (l + r) >> 1;
    if(check(mi)) {
      r = mi;
    } else {
      l = mi + 1;
    }
  }
  cout << n - 1 << " " << l;
  return 0;
}
#endif