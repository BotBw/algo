#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int max(int n,...) {va_list args;va_start(args, n);int ret = INT_MIN;FOR(i, 0, n-1)ret = max(ret, va_arg(args, int));va_end(args);return ret;}
int min(int n,...) {va_list args;va_start(args, n);int ret = INT_MAX;FOR(i, 0, n-1)ret = min(ret, va_arg(args, int));va_end(args);return ret;}
#define DEBUG // if debugging codes are contained, delete this line before submitting

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
#include "leet/TreeNode.h"

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode **p = &root;
        while(*p) {
          if((*p)->val < val) {
            (*p) = (*p)->right;
          } else {
            (*p) = (*p)->left;
          }
        }
        (*p) = new TreeNode(val);
        return root;
    }
};
