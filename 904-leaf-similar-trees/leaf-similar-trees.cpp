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
    int i = 0, n;
    vector<int> leaves;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        n = leaves.size();
        return dfs2(root2) && i == n;
    }

    void dfs(TreeNode* root) {
        if(!root)
            return;

        if(!root->left && !root->right)
            leaves.push_back(root->val);

        dfs(root->left);
        dfs(root->right);
    }

    bool dfs2(TreeNode* root) {
        if(!root)
            return true;

        if(!root->left && !root->right) {
            if(i >= n || leaves[i] != root->val)
                return false;

            cout<<root->val<<" ";
            i++;
        }

        return dfs2(root->left) && dfs2(root->right);
    }
};