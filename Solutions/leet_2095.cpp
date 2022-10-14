#include "bits/stdc++.h"

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dump;
        dump.next = head;
        ListNode *p1 = &dump, *p2 = &dump;
        while(p2 && p2->next && p2->next->next) {
          p1 = p1->next;
          p2 = p2->next->next;
        }
        p1->next = p1->next->next;
        return dump.next;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}