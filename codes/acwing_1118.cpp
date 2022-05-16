#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxn = 15;

int a[maxn];
int grp[maxn][maxn];
int n, ans;
bool used[maxn];

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

bool expand(int gid, int gcnt, int val) {
  FOR(i, 1, gcnt-1) {
    if(gcd(grp[gid][i], val) != 1) {
      return false;
    }
  }
  return true;
}

void dfs(int gid, int gcnt, int acnt, int start) {
  if(gid >= ans) return;
  if(acnt == n) {
    ans = gid;
    return;
  }

  bool newGrp = true;

  FOR(i, start, n) {
    if(!used[i] && expand(gid, gcnt, a[i])) {
      newGrp = false;

      used[i] = true;
      grp[gid][gcnt] = a[i];
      dfs(gid, gcnt + 1, acnt + 1, i + 1);
      used[i] = false;
    }
  }

  if(newGrp) {
    dfs(gid + 1, 1, acnt, 1);
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  ans = n;

  dfs(1, 1, 0, 1);
  cout << ans;
  return 0;
}
#endif