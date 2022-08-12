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

const int N = 205;

bool g[N][N];
bool grp[N];
int a[N];

int n, m, k;

int main() {
  cin >> n >> m;

  FOR(i, 1, m) {
    int a, b;
    cin >> a >> b;
    g[a][b] = g[b][a] = true;
  }

  cin >> k;

  FOR(i, 1, k) {
    memset(grp, 0, sizeof grp);

    int l;
    cin >> l;

    FOR(j, 1, l) {
      cin >> a[j];
      grp[a[j]] = true;
    }

    int H = 0;
    bool ok = true;

    FOR(u, 1, n) {
      bool allCon = true;
      FOR(j, 1, l) {
        if(u == a[j]) continue;
        int v = a[j];
        if(!g[u][v]) allCon = false;
      }
      if(grp[u] && !allCon) {
        ok = false;
        break;
      }
      if(!grp[u] && allCon && !H) H = u;
    }

    if(ok) {
      if(H) printf("Area %d may invite more people, such as %d.\n", i, H);
      else printf("Area %d is OK.\n", i);
    } else printf("Area %d needs help.\n", i);
  }
  return 0;
}
