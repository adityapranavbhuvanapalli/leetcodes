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
    int findBottomLeftValue(TreeNode* root) {
        int res, sz;
        bool first;
        TreeNode* cur;
        queue<TreeNode*> q;

        q.push(root);
        while(q.size()) {
            sz = q.size();
            first = false;
            while(sz--) {
                cur = q.front();
                if(cur && !first) {
                    first = true;
                    res = cur->val;
                }

                if(cur->left)
                    q.push(cur->left);

                if(cur->right)
                    q.push(cur->right);
                q.pop();
            }
        }

        return res;
    }
};