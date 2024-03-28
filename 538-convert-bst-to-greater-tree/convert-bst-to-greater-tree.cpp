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
    TreeNode* convertBST(TreeNode* root) {
        int val = 0;
        convert(root, val);
        return root;
    }

    void convert(TreeNode* root, int& val) {
        if(!root)
            return;

        convert(root->right, val);
        root->val += val;
        val = root->val;
        convert(root->left, val);
    }
};