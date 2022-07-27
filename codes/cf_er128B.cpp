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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int cnt = 0;
    FOR(i, 0, n-1) {
      FOR(j, 0, m-1) {
        cin >> grid[i][j];
        if(grid[i][j] == 'R') cnt++;
      }
    }
    bool ok = false;
    [&]() {
      FOR(i, 0, n-1) {
        FOR(j, 0, m-1) {
          if(grid[i][j] != 'R') continue;
          int tmp = 0;
          FOR(x, i, n-1) {
            FOR(y, j, m-1) {
              if(grid[x][y] == 'R') tmp++;
            }
          }
          if(tmp == cnt) {
            ok = true;
            return;
          }
        }
      }
    } ();
    if(ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}