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

int door[4];
bool vis[4];
vector<int> a;
int x;

bool dfs(int num) {
  if(num == 3) return true;
  FOR(i, 1, 3) {
    if(!vis[i]) {
      bool has = false;
      for(auto v:a) {
        if(v == i) {
          has = true;
          break;
        }
      }
      if(has) {
        debug(i);
        a.push_back(door[i]);
        vis[i] = true;
        if(dfs(num + 1)) {
          return true;
        }
      }
    }
  }
  return false;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;

  FOR(t, 1, tt) {
    memset(vis, 0, sizeof vis);
    a.clear();
    cin >> x;
    a.push_back(x);
    FOR(i, 1, 3) {
      cin >> door[i];
    }
    if(dfs(0))
      cout << "YES\n";
    else {
      cout << "NO\n";
    }
  }
  return 0;
}