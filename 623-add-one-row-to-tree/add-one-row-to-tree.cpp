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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int level = 1, n;

        if (depth == 1)
            return new TreeNode(val, root, NULL);

        queue<TreeNode*> q;
        TreeNode* cur;
        q.push(root);

        // BFS
        while (q.size()) {
            n = q.size();
            level++;
            for (int i = 0; i < n; i++) {
                cur = q.front();
                if (level == depth) {
                    // Add val nodes at depth
                    cur->left = new TreeNode(val, cur->left, NULL);
                    cur->right = new TreeNode(val, NULL, cur->right);
                }

                // Add to Queue
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                q.pop();
            }
            if (level == depth)
                return root;
        }
        return root;
    }
};