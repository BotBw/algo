#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)

const int N = 150005;
int n;
int arr[N];
unordered_map<int,int> m;

int main() {
  int t;
  cin >> t;
  while(t--) {
    m.clear();
    cin >> n;
    int res = -1;
    FOR(i, 1, n) {
      int a;
      scanf("%d", &a);
      if(!m.count(a)) m[a] = i;
      else {
        res = max(res, m[a] + n - i);
        m[a] = i;
      }
      // cout << res << " ";
    }
    printf("%d\n", res);
  }
  return 0;
}