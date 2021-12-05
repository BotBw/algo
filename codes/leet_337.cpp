#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

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
    unordered_map<TreeNode*, int> m2;
    int rob(TreeNode* root) {
        m2[0] = 0;
        dfs(root);
        return m2[root];
    }
    
    void dfs(TreeNode *root) {
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        int rob_x = root->val;
        if(root->left) {
            rob_x += m2[root->left->left] + m2[root->left->right];
        }
        if(root->right) {
            rob_x += m2[root->right->left] + m2[root->right->right];
        }
        int not_rob_x = m2[root->left] + m2[root->right];
        m2[root] = max(rob_x, not_rob_x);
    }
};