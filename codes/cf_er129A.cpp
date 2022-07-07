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
typedef vector<int> VI;
typedef vector<LL> VLL;


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n;
    cin >> n;
    int max1 = 0;
    FOR(i, 1, n) {
      int a;
      cin >> a;
      max1 = max(max1, a);
    }
    int m;
    cin >> m;
    int max2 = 0;
    FOR(i, 1, m) {
      int a;
      cin >> a;
      max2 = max(max2, a);
    }
    if(max1 == max2) {
      cout << "Alice\nBob\n";
    } else {
      if(max1 > max2) {
        cout << "Alice\nAlice\n";
      } else {
        cout << "Bob\nBob\n";
      }
    }
  }
  return 0;
}