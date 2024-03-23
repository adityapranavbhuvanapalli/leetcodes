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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;

        ListNode *cur = head;

        for(ListNode* fast=head->next; fast && fast->next; cur=cur->next, fast=fast->next->next);

        ListNode *m = cur->next;
        cur->next = nullptr;

        while(m) {
            s.push(m);
            m = m->next;
        }

        cur = head;

        while(s.size()) {
            m = s.top();
            s.pop();
            m->next = cur->next;
            cur->next = m;
            cur = cur->next->next;
        }
    }
};