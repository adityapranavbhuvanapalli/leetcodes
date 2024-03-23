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

        ListNode *slow = head;

        for(ListNode* fast=head->next; fast && fast->next; slow=slow->next, fast=fast->next->next);

        ListNode *cur = slow->next;
        slow->next = nullptr;

        while(cur) {
            s.push(cur);
            cur = cur->next;
        }

        slow = head;

        while(s.size()) {
            cur = s.top();
            s.pop();
            cur->next = slow->next;
            slow->next = cur;
            slow = slow->next->next;
        }
    }
};