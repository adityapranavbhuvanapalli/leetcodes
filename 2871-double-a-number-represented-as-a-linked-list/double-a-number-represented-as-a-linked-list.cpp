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
        int carry = 0;
        stack<ListNode*> s;
        while(head) {
            s.push(head);
            head = head->next;
        }

        while(s.size()) {
            head = s.top();
            head->val = (2 * head->val + carry);
            carry = head->val/10;
            head->val %= 10;
            s.pop();
        }

        if(carry)
            return new ListNode(carry, head);
        
        return head;
    }
};