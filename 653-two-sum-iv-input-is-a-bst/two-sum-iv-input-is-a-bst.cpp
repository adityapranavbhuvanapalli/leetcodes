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
    map<pair<TreeNode*, TreeNode*>, bool> dp;
    bool findTarget(TreeNode* root, int k) { 
        return solve(root, root, k); 
    }

    bool solve(TreeNode* l, TreeNode* r, int k) {
        if (!l || !r)
            return false;

        // cout<<l->val<<" "<<r->val<<endl;
        if(dp.count({l, r}) == 1)
            return dp[{l, r}];

        if(l == r) 
            return dp[{l, r}] = solve(l->left, r, k) || solve(l, r->right, k);

        int sum = l->val + r->val;

        if (sum > k) {
            return dp[{l, r}] = solve(l->left, r, k) || solve(l, r->left, k);
        } else if (sum < k) {
            return dp[{l, r}] = solve(l->right, r, k) || solve(l, r->right, k);
        }

        return dp[{l, r}] = true;
    }
};