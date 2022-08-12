#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
string a, b;
string modify[7][2];
int n = 0;
int extend(queue<string> &q, unordered_map<string, int> &dis, unordered_map<string, int> &odis, bool rev) {
  int from, to;
  from = 0, to = 1;
  if(rev) {
    from = 1, to = 0;
  }
  int d = dis[q.front()];
  while (q.size() && dis[q.front()] == d) {
    auto frt = q.front();
    q.pop();

    // printf("%s:%d\n", frt.c_str(), dis[frt]);

    FOR(i, 1, n) {
      FOR(j, 0, frt.size()-1) {
        if(frt.substr(j, modify[i][from].size()) == modify[i][from]) {
          string ne = frt.substr(0, j) + modify[i][to] + frt.substr(j + modify[i][from].size());
          if(odis.count(ne)) return odis[ne] + dis[frt] + 1;
          if(dis.count(ne)) continue;
          dis[ne] = dis[frt] + 1;
          q.push(ne);
        }
      }
    }
  }
  return 100;
}
int bfs() {
  if(a == b) return 0;
  queue<string> q1;
  unordered_map<string, int> vis1;
  queue<string> q2;
  unordered_map<string, int> vis2;

  vis1[a] = 0;
  vis2[b] = 0;

  q1.push(a);
  q2.push(b);

  int cnt = 0;
  while(!q1.empty() && !q2.empty()) {
    int ret;
    if(q1.size() < q2.size()) ret = extend(q1, vis1, vis2, 0);
    else ret = extend(q2, vis2, vis1, 1);

    cnt++;

    if(ret <= 10)  
      return ret;
    if(cnt > 10) 
      return 100;
  }

  return 100;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> a >> b;
  string c, d;
  while(cin >> c && cin >> d) {
    n++;
    modify[n][0] = c;
    modify[n][1] = d;
  }
  // FOR(i, 1, n) {
  //   cout << modify[i][0] << ":" << modify[i][1] << endl;
  // }
  int ans = bfs();
  if(ans > 10) {
    cout << "NO ANSWER!\n";
  } else {
    cout << ans << endl;
  }
  return 0;
}
#endif