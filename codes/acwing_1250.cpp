#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
vector<int> fa;
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int getId(int x, int y) {
  return x * n + y;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  n++;
  fa = vector<int>(n * n);
  for(int i = 0; i < fa.size(); i++) fa[i] = i;
  FOR(i, 1, m) {
    int a, b;
    char dir;
    cin >> a >> b >> dir;
    int x, y;
    if(dir == 'D') x = a + 1, y = b;
    else x = a, y = b + 1;
    int from = getId(a, b), to = getId(x, y);
    int fa1 = find(from), fa2 = find(to);
    debug(a, b, x, y);
    if(fa1 == fa2) {
      cout << i;
      return 0;
    } else {
      fa[fa1] = fa2;
    }
    cout << "draw";
  }
  return 0;
}