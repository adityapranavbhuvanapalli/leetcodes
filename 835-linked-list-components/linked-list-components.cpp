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
    int numComponents(ListNode* head, vector<int>& nums) {
        int count = 0, len = 0;
        unordered_set<int> uniq(nums.begin(), nums.end());

        while (head) {
            if (uniq.count(head->val) == 0) {
                count += (len > 0);
                len = 0;
            } else {
                len++;
            }
            head = head->next;
        }

        return (len > 0) + count;
    }
};