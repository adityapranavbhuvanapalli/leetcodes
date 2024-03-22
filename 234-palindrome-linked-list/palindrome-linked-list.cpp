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
    bool isPalindrome(ListNode* head) {
        if(!head->next)
            return true;

        // Find middle
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }    

        // Reverse till slow
        ListNode *prev = nullptr, *cur = head, * next;
        while(cur != slow) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // If odd length ignore the middle one
        if(fast)
            slow = slow->next;

        // Check
        cur = prev;
        while(slow) {
            if(slow->val != cur->val)
                return false;
            slow = slow->next;
            cur = cur->next;
        }

        return true;
    }
};

/*
1   2   3   4   5
        s
                f
*/