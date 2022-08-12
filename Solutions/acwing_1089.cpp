#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 2e5 + 10;

int f[N], a[N];
// f[i] = min{a[k] + f[k-1]} (i - m + 1 <= k <= i)
#ifdef LEET
#include "leet.h"
#else
int main() {
  int n, m;
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];
  deque<int> q;
  q.push_back(0);
  FOR(i, 1, n) {
    if(q.front() < i - m + 1) q.pop_front();
    while(q.size() && a[q.back()] + f[q.back() - 1] >= a[i] + f[i-1]) q.pop_back();
    q.push_back(i);
    f[i] = a[q.front()] + f[q.front() - 1];
    // cout << f[i] << "  ";
  }
  cout << f[n];
  return 0;
}
#endif