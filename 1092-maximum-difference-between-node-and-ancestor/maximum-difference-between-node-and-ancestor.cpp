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
    int res = -1;
    int maxAncestorDiff(TreeNode* root) {
        vector<int> ancestors;
        dfs(root, ancestors);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& ancestors) {
        if(!root)
            return;

        for(const auto& ancestor: ancestors)
            res = max(res, abs(ancestor - root->val));

        ancestors.push_back(root->val);
        dfs(root->left, ancestors);
        dfs(root->right, ancestors);
        ancestors.pop_back();
    }
};