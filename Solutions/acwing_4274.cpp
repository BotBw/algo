#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#endif

const int N = 25;

struct node {
  string data;
  int l, r;
} t[N];
int n;
bool notRt[N];

void dfs(int u) {
  putchar('(');
  if(t[u].r && !t[u].l) {
    cout << t[u].data;
    dfs(t[u].r);
    cout << ')';
    return;
  }
  if(t[u].l) dfs(t[u].l);
  if(t[u].r) dfs(t[u].r);
  cout << t[u].data;
  putchar(')');
}

int main() {
  cin >> n;
  FOR(i, 1, n) {
    string data;
    int l, r;
    cin >> data >> l >> r;
    l = l == -1 ? 0 : l;
    r = r == -1 ? 0 : r;
    t[i].data = data;
    t[i].l = l;
    t[i].r = r;
    notRt[l] = true;
    notRt[r] = true;
    // cout << data << " ";
    // printf("%d %d\n", l ,r);
  }
  FOR(i, 1, n) {
    if(!notRt[i]) {
      dfs(i);
      break;
    }
  }
  return 0;
}
