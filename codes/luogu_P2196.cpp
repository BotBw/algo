#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxn = 25;

int a[maxn];
bool connect[maxn][maxn];
int f[maxn], nxt[maxn];

int N, ans, ans_id;

int dfs(int x) {
  if(f[x]) return f[x];
  int maxF, maxF_i;
  maxF = 0, maxF_i = 0;
  FOR(i, 1, N) {
    if(connect[x][i]) {
      int tmp = dfs(i);
      if(tmp > maxF) {
        maxF = tmp;
        maxF_i = i;
      }
    }
  }
  f[x] = maxF + a[x];
  nxt[x] = maxF_i;
  if(f[x] > ans) {
    ans = f[x];
    ans_id = x;
  }
  return f[x];
}
int main(int argc, char *args[]) {
  cin >> N;
  FOR(i, 1, N) cin >> a[i];

  FOR(i, 1, N)
    FOR(j, i+1, N)
      cin >> connect[i][j];
  FOR(i, 1, N) dfs(i);
  for(int i = ans_id; i; i = nxt[i]) {
    cout << i << ' ';
  }
  cout << endl;
  cout << ans;

  return 0;
}