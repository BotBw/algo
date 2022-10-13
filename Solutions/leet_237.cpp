#include "bits/stdc++.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *p1 = node->next, *p2 = node;
        while(p1->next) {
          p2->val = p1->val;
          p2 = p1;
          p1 = p1->next;
        }
        p2->val = p1->val;
        p2->next = nullptr;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}