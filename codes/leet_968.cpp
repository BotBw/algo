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
class Solution {
public:
    // f[st][u]
    // 0 by parent, 1 by itself, 2 by child
    // f[0][u] = min{f[st1][l] + f[st2][r]}; // st1 st2 != 0
    // f[1][u] = min{f[st1][l] + f[st2][r]} + 1;
    // f[2][u] = min(f[1][l] + f[2][r], f[2][l] + f[1][r], f[1][l] + f[1][r]);
    static const int INF = 0x3f3f3f3f;
    
    unordered_map<TreeNode*, int> f[3];

    int minCameraCover(TreeNode* root) {
      dfs(root);
      return min(f[1][root], f[2][root]);
    }

    void dfs(TreeNode* u) {
      f[0][u] = 0;
      f[1][u] = 1;
      f[2][u] = 0;
      TreeNode *l = u->left, *r = u->right;
      TreeNode *arr[2] = {l, r};
      bool selected = false;
      int diff = INF;
      for(int i = 0; i < 2; i++) {
          TreeNode* v = arr[i];
          if(!v) continue;
          dfs(v);
          f[0][u] += min(f[1][v], f[2][v]);
          f[1][u] += min(f[0][v], min(f[1][v], f[2][v]));
          if(f[1][v] <= f[2][v]) {
              selected = true;
              f[2][u] += f[1][v];
          } else {
              f[2][u] += f[2][v];
              diff = min(diff, f[1][v] - f[2][v]);
          }
      }
      if(!selected) {
          f[2][u] += diff;
      }
    }
};
