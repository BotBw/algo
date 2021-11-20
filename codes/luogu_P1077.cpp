#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

int n, m;
int a[105];
int f[105];
const int MOD = 1e6+7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  f[0] = 1;
  FOR(i, 1, n) cin >> a[i];

  FOR(i, 1, n) {
    _FOR(mm, m, 0) {
      int fSum = 0;
      FOR(cc, 0, min(mm, a[i])) {
        fSum += f[mm-cc];
        fSum %= MOD;
      }
      f[mm] = fSum;
    }
  }
  cout << f[m];
  return 0;
}