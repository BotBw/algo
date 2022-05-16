#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxn = 25;

string words[maxn];
char st;
int n;
int cnt[maxn];
int cat[maxn][maxn];
int ans = 1;

void dfs(int pre, int sz) {
  if(sz > ans) ans = sz;

  FOR(i, 1, n) {
    if(cat[pre][i] && cnt[i] < 2) {
      cnt[i]++;
      dfs(i, sz+words[i].size() - cat[pre][i]);
      cnt[i]--;
    }
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n;
  FOR(i, 1, n) {
    cin >> words[i];
  }
  FOR(i, 1, n) {
    FOR(j, 1, n) {
      for(int k = 1; k < min(words[i].size(), words[j].size()); k++) {
        if(words[i].substr(words[i].size()-k) == words[j].substr(0, k)) {
          cat[i][j] = k;
          break;
        }
      }
    }
  }
  // FOR(i, 1, n) {
  //   FOR(j, 1, n) {
  //     cout << cat[i][j] << "   ";
  //   }
  //   cout << endl;
  // }
  cin >> st;
  FOR(i, 1, n) {
    if(words[i][0] == st) {
      cnt[i] = 1;
      dfs(i, words[i].size());
      cnt[i] = 0;
    }
  }
  cout << ans;
  return 0;
}
#endif