#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)

const int N = 2005;
int arr[N];

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    int res = 0;
    FOR(i, 1, n) {
      int x;
      cin >> x;
      res = max(res, k | x);
    }
    cout << res << endl;
  }
  return 0;
}