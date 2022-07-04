#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int a, b;
    cin >> a >> b;
    int cnt = 1;
    while(cnt <= min(a, b)) {
      cout << "01";
      cnt++;
    }
    FOR(i,cnt,a) cout << "0";
    FOR(i,cnt, b) cout << "1";
    cout << "\n";
  }
  return 0;
}