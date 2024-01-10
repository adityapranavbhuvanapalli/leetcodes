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
    bool findTarget(TreeNode* root, int k) { 
        return solve(root, root, k); 
    }

    bool solve(TreeNode* l, TreeNode* r, int k) {
        if (!l || !r)
            return false;

        if(l == r) 
            return solve(l->left, r, k) || solve(l, r->right, k);

        int sum = l->val + r->val;

        if (sum > k) {
            return solve(l->left, r, k) || solve(l, r->left, k) || solve(l->left, r->left, k);
        } else if (sum < k) {
            return solve(l->right, r, k) || solve(l, r->right, k) || solve(l->right, r->right, k);
        }

        return true;
    }
};