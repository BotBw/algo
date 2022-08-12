#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
#define maxE 500005
#define maxV 5005
// delete this line when submitting
#define DEBUG

#ifdef maxV
#ifdef maxE
int head[maxV], cnt;
bool notTop[maxV];

struct edge {
  int u, v, w, next;
} e[maxE];

void addE(int u, int v, int w) {
  e[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}
#endif
#endif

int n, m;
const int MOD = 80112002;
int f[maxV];

int dfs(int u) {
  if(f[u]) return f[u];
  int sumF = 0;
  if(head[u] == 0) {
    f[u] = 1;
    return 1;
  }
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    sumF += dfs(v);
    sumF %= MOD;
  }
  f[u] = sumF;
  return f[u];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  FOR(i ,1, m) {
    int a, b;
    cin >> a >> b;
    addE(b, a, 1);
    notTop[a] = 1;
  }
  int ans = 0;
  FOR(i, 1, n) {
    if(!notTop[i]) {
      ans += dfs(i);
      ans %= MOD;
    }
  }
  cout << ans;
  return 0;
}