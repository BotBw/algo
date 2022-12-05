#include "bits/stdc++.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return nullptr;
        ListNode *p1, *p2;
        p1 = p2 = head;

        while(p2->next && p2->next->next) {
          p2 = p2->next->next;
          p1 = p1->next;
        }
        if(!p2->next) return p1;
        else return p1->next;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}