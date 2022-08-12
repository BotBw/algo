#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#ifdef LEET
#include "leet.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node dumb;
        queue<Node*> q;
        int psz = 0;
        if(root) {
            q.push(root);
            psz++;
        }
        while(!q.empty()) {
            Node *p = &dumb;
            while(psz) {
                psz--;
                Node *cur = q.front(); q.pop();
                p->next = cur;
                p = cur;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            psz = q.size();
        }
        return root;
    }
};
#else
int main() {
  return 0;
}
#endif