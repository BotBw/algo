#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)


const int N = 100005;

LL sum[N];
LL f[N];
LL ans = -1;
int n, k;

// f[i] = max{f[j-1] + sum[i] - sum[j]} {0 <= i - j <= k}
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> k;
  FOR(i, 1, n) {
    cin >> sum[i];
    sum[i] += sum[i-1];
  }

  deque<int> q;
  q.push_back(0);
  FOR(i, 1, n) {
    while(q.size() && f[i-1] - sum[i] >= f[q.back()-1] - sum[q.back()]) q.pop_back();
    q.push_back(i);
    if(q.size() && q.front() < i - k) q.pop_front();
    f[i] = f[q.front()-1] + sum[i] - sum[q.front()];
    ans = max(ans, f[i]);
  }
  cout << f[n];
  return 0;
}
#endif