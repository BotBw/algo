#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 1e5+5, M = 4e5 + 5, MOD = 100003;


typedef pair<int, int> PII;

int n, m;

struct edge  {
  int v, next;
} e[M];

int head[N], cnt;

void add(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}

int dist[N], cntt[N];
bool st[N];
int q[N];

void spfa()
{
    int hh = 0, tt = 0;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    cntt[1] = 1;
    q[tt ++ ] = 1;
    st[1] = true;

    while (hh != tt)
    {
        int t = q[hh ++ ];
        if (hh == N) hh = 0;
        st[t] = false;
        
        for (int i = head[t]; i ; i = e[i].next)
        {
            int j = e[i].v;
            if (dist[j] > dist[t] + 1)
            {
                dist[j] = dist[t] + 1;
                cntt[j] = cntt[t];
                if (!st[j])
                {
                    q[tt ++ ] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            } else if(dist[j] == dist[t] + 1) {
              cntt[j] += cntt[t];
              cntt[j] %= MOD;
            }
        }
    }
}


#ifdef LEET
#include "leet.h"
#else
int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  spfa();
  FOR(i, 1, n) {
    printf("%d\n", cntt[i]);
  }
  return 0;
}
#endif