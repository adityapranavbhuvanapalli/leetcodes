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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = new ListNode(-1, head);
        ListNode *start, *end, *cur = root;

        while(cur && cur->next) {
            start = end = cur->next;

            while(end && end->next && end->next->val == end->val) 
                end = end->next;

            if(start != end) {
                cur->next = end->next;
            } else {
                cur = cur->next;
            }
        }

        return root->next;
    }
};