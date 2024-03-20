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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 0;        
        ListNode *left = nullptr, *right = nullptr, *cur = list1;
        while(i <= b + 1) {
            if(i < a)
                left = cur;
            else
                right = cur;

            cur = cur->next;
            i++;
        }

        cur = list2;
        while(cur->next)
            cur = cur->next;

        left->next = list2;
        cur->next = right;

        return list1;
    }
};