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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    queue<TreeNode*> q;
    void dfs(TreeNode* root, int val) {
        if(!root)
            return;

        if(root->val == val)
            q.push(root);

        dfs(root->left, val);
        dfs(root->right, val);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        dfs(root, head->val);

        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto cur = q.front();
                q.pop();

                if(head->val != cur->val) 
                    continue;

                if(!head->next)
                    return true;

                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }

            head = head->next;
        }

        return false;
    }
};

/*

*/