#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG
const int maxm = 1e5+ 10;
const int maxn = 2e4+10;

struct edge {
  int u, v, next;
} e[maxm*2];

int head[maxn], cnt;
void addE(int u, int v) {
  e[++cnt] = {u, v, head[u]};
  head[u] = cnt;
}
void addUE(int u, int v) {
  addE(u, v);
  addE(v, u);
}

int n, m;
int dfsn[maxm], dfscnt;
int low[maxm];
bool isCut[maxm];
int ans;
void tarjan(int u, bool root) {
  dfsn[u] = low[u] = ++dfscnt;
  int count = 0;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(!dfsn[v]) {
      tarjan(v, 0);
      low[u] = min(low[u], low[v]);
      if(low[v] >= dfsn[u]) count++;
    } else {
      low[u] = min(low[u], dfsn[v]);
    }
  }
  if(count > root) isCut[u] = 1, ans++; 
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  FOR(i, 1, m) {
    int u, v;
    cin >> u >> v;
    addUE(u, v);
  }
  FOR(i, 1, n) if(!dfsn[i]) tarjan(i, 1);
  cout << ans << '\n';
  FOR(i, 1, n) if(isCut[i]) cout << i << ' ';
  
  return 0;
}