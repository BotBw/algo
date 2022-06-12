#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 300005;

LL sum[N];
int n, m;
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  FOR(i, 1, n) {
    LL a;
    cin >> a;
    sum[i] = sum[i-1] + a;
  }
  // f[i] = max(sum[i] - sum[k]) (k < i && k >= i - m)
  LL ans = LLONG_MIN;
  deque<int> q;
  q.push_back(0);
  FOR(i, 1, n) {
    while(q.size() && q.front() < i - m) q.pop_front();
    ans = max(ans, sum[i] - sum[q.front()]);
    while(q.size() && sum[q.back()] >= sum[i]) q.pop_back();
    q.push_back(i);
  }
  cout << ans;
  return 0;
}
#endif