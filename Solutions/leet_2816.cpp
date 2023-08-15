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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> s;
        auto p = head;
        while(p) {
            s.push(p);
            p = p->next;
        }
        int c = 0;
        while(s.size()) {
            auto cur = s.top();
            s.pop();
            int val = cur->val * 2;
            cur->val = val % 10;
            cur->val += c;
            c = val / 10;
        }
        if(c) {
            auto p = new ListNode(c);
            p->next = head;
            return p;
        }
        return head;
    }
};
