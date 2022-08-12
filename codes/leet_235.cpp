#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#include "leet/TreeNode.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    static const int N = 18;
    unordered_map<TreeNode*, vector<TreeNode*>> f;
    unordered_map<TreeNode*, int> dep;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f[nullptr] = vector<TreeNode*>(N, nullptr);
        dfs(root, nullptr, 1);
        return LCA(p, q);
    }

    TreeNode* LCA(TreeNode *a, TreeNode *b) {
      if(dep[a] > dep[b]) swap(a, b);
      int diff = dep[b] - dep[a];
      for(int i = 0; diff; diff >>= 1, i++) {
        if(diff & 1) {
          b = f[b][i];
        }
      }
      if(a == b) return a;
      _FOR(i, N-1, 0) {
        if(f[a][i] != f[b][i]) {
          a = f[a][i];
          b = f[b][i];
        }
      }
      return f[a][0];
    }

    void dfs(TreeNode *x, TreeNode *fa, int d) {
      dep[x] = d;
      f[x].push_back(fa);
      FOR(i, 1, N-1) {
        f[x].push_back(f[f[x][i-1]][i-1]);
      }
      if(x->left) dfs(x->left, x, d + 1);
      if(x->right) dfs(x->right, x, d + 1);
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  return 0;
}