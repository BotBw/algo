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
struct TreeNode;
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val < key) root->right = deleteNode(root->right, key);
        else if(key < root->val) root->left = deleteNode(root->left, key);
        else {
          TreeNode *ret;
          if(!root->left) {
            ret = root->right;
            delete root;
            return ret;
          } else if(!root->right) {
            ret = root->left;
            delete root;
            return ret;
          } else {
            TreeNode *p = root->right;
            while(p->left) p = p->left;
            swap(root->val, p->val);
            root->right = deleteNode(root->right, p->val);
            return root;
          }
        }
        return root;
    }
};