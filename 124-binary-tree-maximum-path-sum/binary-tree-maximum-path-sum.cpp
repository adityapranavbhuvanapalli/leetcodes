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
    int maxVal = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxVal;
    }

    int dfs(TreeNode* root){
        if(!root)
            return 0;

        int val = root->val;
        int l = dfs(root->left);
        int r = dfs(root->right);

        maxVal = max({maxVal, val + l + r, val + l, val + r, val});

        return max({val, val + l, val + r});
    }
};