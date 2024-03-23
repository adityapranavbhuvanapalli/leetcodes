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
        ListNode *slow = head;

        for(ListNode* fast=head->next; fast && fast->next; slow=slow->next, fast=fast->next->next);

        ListNode *prev = nullptr, *cur = slow->next, *next;
        slow->next = nullptr;

        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        ListNode *cur1 = head, *cur2 = prev;
        next = nullptr;    
        while(cur1 && cur2) {
            next = cur1->next;
            cur1->next = cur2;
            cur2 = cur2->next;

            cur1->next->next = next;
            cur1 = next;
        }
    }
};