#include <bits/stdc++.h>
using namespace std;

const int N = 20, ST = 1 << 20;

int g[N][N];
int n;

int f[N][ST];
bool valid[N][ST];

int dfs(int v, int st) {
  if(!(1 << v & st)) return 0x3f3f3f3f;
  if(valid[v][st]) return f[v][st];
  for(int u = 0; u < n; u++) {
    if(u == v || !g[u][v]) continue;
    int val = dfs(u, st & ~(1 << v));
    f[v][st] = min(f[v][st], val + g[u][v]); 
  }
  valid[v][st] = true;
  return f[v][st];
}

void print(int x) {
  for(int i = n - 1; i >= 0; i--)
    printf("%d", x >> i & 1);
}

// f[v][st] = min(f[u][st | ~(1 << v)] + dis[u][v]);

int main() {
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &g[i][j]);
  memset(f, 0x3f, sizeof f);

  f[0][1] = 0;
  valid[0][1] = true;
  
  // for(int st = 0; st < 1 << n; st++) {
  //   for(int v = 0; v < n; v++) {
  //     if(!(st & 1 << v)) continue;
  //     for(int u = 0; u < n; u++) {
  //       if(u == v) continue;
  //       if(!(st & 1 << u)) continue;
  //       f[v][st] = min(f[v][st], f[u][st & ~(1 << v)] + g[u][v]);
  //     }
  //   }
  // }
  printf("%d", dfs(n-1, (1 << n) - 1));
  return 0;
}