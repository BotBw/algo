#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

string start(9, '0'), endd{"12345678x"};
typedef pair<string, char> PIC;
unordered_map<string, PIC> pre;
unordered_map<string, int> d;
queue<string> q;

typedef pair<int, string> PIS;

char cg[] = "udlr";
char dx[] = {-1, 1, 0, 0};
char dy[] = {0, 0, -1, 1};

int h(const string &s) {
  int ret = 0;
  FOR(i, 0, 8) {
    if(s[i] == 'x') continue;
    int x = i/3, y = i%3;
    int c = s[i] - '1', xx = c/3, yy = c%3;
    ret += abs(xx-x) + abs(yy - y);
  }
  return ret;
}

void astar() {
  priority_queue<PIS, deque<PIS>, greater<PIS>> q;
  d[start] = 0;
  q.push({h(start), start});

  while (!q.empty()) {
    auto cur = q.top();
    q.pop();
    string frt = cur.second;
    // cout << frt << endl;
    if(frt == endd) break;
    int x, y, id1;
    FOR(i, 0, 8) {
      if(frt[i] == 'x') {
        id1 = i;
        x = i/3;
        y = i%3;
        break;
      }
    }
    FOR(i, 0, 3) {
      int xx = x + dx[i], yy = y + dy[i];
      int id2 = xx * 3 + yy;
      if(xx < 0 || xx >= 3 || yy < 0 || yy >= 3) continue;
      string ne = frt;
      swap(ne[id1], ne[id2]);
      if(d.count(ne) == 0 || d[ne] > d[frt] + 1) {
        d[ne] = d[frt] + 1;
        pre[ne] = {frt, cg[i]};
        q.push({d[ne] + h(ne), ne});
      }
    }
  }
  string p = endd;
  string o;
  while(p != start) {
    o += pre[p].second;
    p = pre[p].first;
  }
  reverse(o.begin(), o.end());
  cout << o;
}

// void bfs() {
//   q.push(start);
//   pre[start] = {"non", 'a'};
//   while(!q.empty()) {
//     string frt = q.front();
//     q.pop();
//     // cout << frt << endl;
//     int x, y, id1;
//     FOR(i, 0, 8) {
//       if(frt[i] == 'x') {
//         id1 = i;
//         x = i/3;
//         y = i%3;
//         break;
//       }
//     }
//     FOR(i, 0, 3) {
//       int xx = x + dx[i], yy = y + dy[i];
//       int id2 = xx * 3 + yy;
//       if(xx < 0 || xx >=3 || yy < 0 || yy >= 3) continue;
//       string ne = frt;
//       swap(ne[id1], ne[id2]);
//       if(pre.count(ne)) continue;
//       pre[ne] = {frt, cg[i]};
//       q.push(ne);
//     }
//   }
//   string p = endd;
//   string o;
//   while(p != start) {
//     o += pre[p].second;
//     p = pre[p].first;
//   }
//   reverse(o.begin(), o.end());
//   cout << o;
// }

#ifdef LEET
#include "leet.h"
#else
int main() {
  FOR(i, 1, 9) {
    cin >> start[i-1];
  }
  int rev = 0;
  FOR(i, 0, 8) {
    if(start[i] == 'x') continue;
    FOR(j, 0, i-1) {
      if(start[j] == 'x') continue;
      if(start[j] > start[i]) rev++;
    }
  }
  if(rev % 2) printf("unsolvable\n");
  else astar();
  return 0;
}
#endif