#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)
typedef long long ll;

void solve() {
  ll cost = 0;
  int n, m;
  cin >> n >> m;
  int i = 1, j = 1;
  while(j <= m) {
    cost += (i - 1) * m + j;
    j++;
  }
  j--;
  i++;
  while(i <= n) {
    cost += (i - 1) * m + j;
    i++;
  }
  cout << cost << endl;
}


int main() {
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
}