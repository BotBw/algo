#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 505, M = 100 * N * N;

struct edge {
  int v, w, nxt;
} e[M];

int m, n;

int head[N], cnt;

int line[N];

void add(int a, int b, int c) {
  e[++cnt] = {b, c, head[a]};
  head[a] = cnt;
}
int dis[N];
bool inq[N];
void spfa() {
  if(1 == n) {
    dis[n] = 1;
    return;
  }

  memset(dis, 0x3f, sizeof dis);
  inq[1] = true;
  dis[1] = 0;
  queue<int> q;
  q.push(1);

  while(q.size()) {
    int u = q.front(); q.pop();
    inq[u] = false;

    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if(!inq[v]) {
          q.push(v);
          inq[v] = true;
        }
      }
    }
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> m >> n;
  getchar();
  FOR(i, 1, m) {
    string str;
    getline(cin, str);
    stringstream ssin(str);
    int j = 1;
    while(ssin >> line[j]) {
      j++;
    }
    j--;
    FOR(a, 1, j) {
      FOR(b, a + 1, j) {
        add(line[a], line[b], 1);
      }
    }
  }
  spfa();
  if(dis[n] == 0x3f3f3f3f) {
    cout << "NO";
  } else 
    cout << dis[n] - 1;
  return 0;
}
#endif