#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#ifdef LEET
#include "leet.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = get_depth(root);
        return dfs(root, depth);
    }
    
    int get_depth(TreeNode *r) {
        if(!r) return 0;
        return max(get_depth(r->left), get_depth(r->right)) + 1;
    }
    
    int dfs(TreeNode* root, int depth) {
        if(!root) return 0;
        if(depth == 1) return root->val;
        return dfs(root->left, depth-1) + dfs(root->right, depth-1);
    }
};
#else
int main() {
  return 0;
}
#endif