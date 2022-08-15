#include "bits/stdc++.h"


#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#include "leet.h"
#include "../mySTL/mySTL.h"
#else
#define debug(...)
#endif
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class Solution {
  struct edge {
    int v, next;
  };
  vector<edge> e;
  vector<int> h;
  vector<unordered_set<int>> pre;
  vector<int> dis;
  vector<vector<string>> res;

  void add(int u, int v) {
    e.push_back({v, h[u]});
    h[u] = e.size() - 1;
  }
  bool check(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    if(n != m) return false;
    int diff = 0;
    FOR(i, 0, n-1) {
      if(a[i] != b[i]) diff++;
      if(diff > 1) return false;
    }
    return true;
  }

  void bfs(int st) {
    queue<int> q;
    dis[st] = 0;
    q.push(st);
    while(q.size()) {
      int u = q.front();
      q.pop();
      for(int i = h[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if(dis[v] < dis[u] + 1) continue;
        else if(dis[v] == dis[u] + 1 && !pre[v].count(u)) {
          pre[v].insert(u);
        } else {
          dis[v] = dis[u] + 1;
          pre[v].insert(u);
          q.push(v);
        }
      }
    }
  }

  void dfs(vector<string> &w, int u, vector<string> &cur, int st) {
    if(!pre[u].size() && u == st) {
      debug(u, w[u]);
      res.push_back(cur);
      return;
    }
    for(auto &v:pre[u]) {
      cur.push_back(w[v]);
      dfs(w, v, cur, st);
      cur.pop_back();
    }
  }

public:
    vector<vector<string>> findLadders(string st, string en, vector<string>& w) {
        int n = w.size();
        h = vector<int>(n + 1, -1);
        FOR(i, 0, n-1) {
          FOR(j, i + 1, n-1) {
            if(check(w[i], w[j])) {
              add(i, j);
              add(j, i);
            }
          }
        }
        FOR(i, 0, n-1) {
          if(check(w[i], st)) {
            add(n, i);
            add(i, n);
          }
        }
        w.push_back(st);
        int st_i = n, en_i = -1;
        FOR(i, 0, n-1) {
          if(w[i] == en) en_i = i;
        }
        if(st_i == -1 || en_i == -1) return {};
        dis = vector<int>(n + 1, INT_INF);
        pre = vector<unordered_set<int>>(n + 1);
        bfs(st_i);
        debug(dis);
        vector<string> cur = {w[en_i]};
        debug(pre);
        dfs(w, en_i, cur, st_i);
        for(auto &v:res) {
          reverse(v.begin(), v.end());
        }
        return res;
    }
};



int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}