#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 10005, M = N * 2;

struct edge {
  int v, w, next;
} e[M];

int head[N], cnt;
int n, ans;

void add(int a, int b, int c) {
  e[++cnt] = {b, c, head[a]};
  head[a] = cnt;
}

int dfs(int u, int fa) {
  int dis = 0;

  int maxd1 = 0, maxd2 = 0;

  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].v, w = e[i].w;

    if (v == fa) continue;
    int d = dfs(v, u) + w;

    dis = max(dis, d);

    if(d >= maxd1) {
      maxd2 = maxd1;
      maxd1 = d;
    } else if (d > maxd2) {
      maxd2 = d;
    }
  }

  ans = max(ans, maxd1 + maxd2);

  return dis;
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  int n;
  cin >> n;

  FOR(i, 1, n-1) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c); add(b, a, c);
  }
  ans = -0x3f3f3f3f;
  dfs(1, 0);
  cout << ans;
  return 0;
}
#endif