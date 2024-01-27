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
    ListNode* sortList(ListNode* head) {
        ListNode* mid = findMid(head);
        
        if(!mid)
            return head;

        ListNode* tail = mid->next;
        mid->next = nullptr;

        head = sortList(head);
        tail = sortList(tail);
        head = merge(head, tail);

        return head;
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode *head = nullptr, *cur = nullptr, *node;

        while(l && r) {
            if(l->val < r->val) {
                node = l;
                l = l->next;
            } else {
                node = r;
                r = r->next;
            }

            if(!head) {
                head = cur = node;
            } else {
                cur->next = node;
                cur = cur->next;
            }
        }

        if(l) {
            if(cur)
                cur->next = l;
            else
                head = l;
        }


        if(r) {
            if(cur)
                cur->next = r;
            else
                head = r;
        }

        return head;
    }

    ListNode* findMid(ListNode* head) {
        if(!head)
            return nullptr;

        ListNode *prev = nullptr, *slow = head, *fast = head;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return prev;
    }
};


/*
-1->5->3    4->0
-1->5   3   4->0
-1  5   3   4   0
-1->5   3   4->0
-1->3->5    4->0
-1->0->3->4->5
*/