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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sum = 0;
        unordered_map<int, ListNode*> prefix;
        unordered_map<ListNode*, int> sums;
        ListNode *cur = head, *start = head;
        
        while(cur) {
            sum += cur->val;
            if(sum == 0) {
                while(start != cur) {
                    prefix.erase(sums[start]);
                    start = start->next;
                }
                start = cur->next;
                cur = start;
                continue;
            }

            if(prefix.count(sum) == 1) {
                // Then remove all elements from prefix[sum] till cur
                // While deleting clear the elements addresses in prefix
                ListNode* tmp = prefix[sum]->next;
                while(tmp != cur) {
                    prefix.erase(sums[tmp]);
                    tmp = tmp->next;
                }
                prefix[sum]->next = cur->next;
            } else {
                // Or else move to the next one
                prefix[sum] = cur;
                sums[cur] = sum;
            }
            cur = prefix[sum]->next;
        }

        return start;
    }
};

/*
1   2   3   -3  -2  -1
1   0

2   -1  0
2   1
*/