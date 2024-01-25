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
    ListNode* root;
    Solution(ListNode* head) {
        root = head;
    }
    
    int getRandom() {
        ListNode* cur = root;
		int random, visitedSize = 0, retVal;

		while(cur) {
			// Either pick cur or don’t pick
			visitedSize++;
			random = rand() % visitedSize;

			if(random == visitedSize - 1) {
				retVal = cur->val;
			}
			cur = cur->next;
		}

		return retVal;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */