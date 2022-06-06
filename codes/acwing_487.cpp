#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 32005, M = 65;

int f[N];

int cost[M], val[M];

vector<int> h[M];
vector<int> item;

int n, m;
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  FOR(i, 1, m) {
    int v, p, q;
    cin >> v >> p >> q;
    cost[i] = v;
    val[i] = v * p;
    if(q) h[q].push_back(i);
    else item.push_back(i);
  }

  for(int i = 0; i < item.size(); i++) {
    int id = item[i];
    for(int cc = n; cc >= 0; cc--) {
      for(int j = 0; j < 1 << h[id].size(); j++) {
        int value = val[id], costt = cost[id];
        for(int k = 0; k < h[id].size(); k++) {
          if(j & 1 << k) value += val[h[id][k]], costt += cost[h[id][k]];
        }
        if(cc - costt >= 0) f[cc] = max(f[cc], f[cc - costt] + value);
      }
    }
  }

  cout << f[n];

  return 0;
}
#endif