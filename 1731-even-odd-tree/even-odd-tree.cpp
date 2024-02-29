/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int n, level = 0, prev;
        queue<TreeNode*> q;
        TreeNode* cur;

        q.push(root);
        while (q.size()) {
            n = q.size();
            prev = (level % 2 == 0) ? INT_MIN : INT_MAX;
            while (n--) {
                cur = q.front();
                q.pop();

                if (level % 2 == 0 && (cur->val % 2 == 0 || cur->val <= prev))
                    return false;
                if (level % 2 == 1 && (cur->val % 2 == 1 || cur->val >= prev))
                    return false;

                prev = cur->val;

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }

            level++;
        }

        return true;
    }
};