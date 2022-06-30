#include <bits/stdc++.h>
using namespace std;

const int N = 16;

int path[N], cnt;

bool vis[N];

int n;

void dfs(int i, int st) {
  if(i == 0) {
    for(int j = 1; j <= cnt; j++) printf("%d ", path[j]);
    puts("");
    return;
  }
  for(int j = st; j <= n; j++) {
    if(vis[j]) continue;
    path[++cnt] = j;
    vis[j] = true;
    dfs(i - 1, j + 1);
    vis[j] = false;
    --cnt;
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i <= n; i++) {
    dfs(i, 1);
  }
  return 0;
}