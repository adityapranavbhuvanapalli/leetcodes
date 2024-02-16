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
    const int MOD = 1e9 + 7;
    long long sum, res = 0;
    int maxProduct(TreeNode* root) {
        sum = dfs(root);
        dfs2(root);
        return res % MOD;
    }

    void dfs2(TreeNode* root) {
        if(!root)
            return;

        dfs2(root->left);
        dfs2(root->right);
        res = max(res, root->val * (long long)(sum - root->val));
    }

    int dfs(TreeNode* root) {
        if(!root)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);
        root->val += (l + r);
        return root->val;
    }
};

/*
        21
                20   
            3           15
                    5       6
*/