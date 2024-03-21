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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int k = 1, n = 0;
        ListNode* tmp;
        for(tmp = head, n = 0; tmp; tmp = tmp->next, n++);

        return reverse(head, n, k);    
    }

    ListNode* reverse(ListNode* head, int n, int k) {
        if(k == 0)
            return nullptr;

        int count = 0;
        ListNode *prev = nullptr, *cur = head, *next;

        k = min(k, n);

        if(k % 2 == 1) {
            // Do not reverse
            while(count < k) {
                prev = cur;
                cur = cur->next;
                count++;
            }                
            prev->next = reverse(cur, n - k, k + 1);
            return head;
        }

        // Reversing if k is even
        while(count < k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count++;
        }

        if(cur)
            head->next = reverse(cur, n - k, k + 1);

        return prev; 
    }
};

/*

*/