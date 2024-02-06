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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int level;
        return dfs(root, level); 
    }
    
    TreeNode* dfs(TreeNode* root, int& level) {
        if(!root) {
            level = 0;
            return nullptr;
        }
        
        int level1, level2;
        TreeNode* l = dfs(root->left, level1);
        TreeNode* r = dfs(root->right, level2);
        
        level = 1 + max({level1, level2});

        // cout<<root->val<<": "<<level1<<" "<<level2<<" "<<level<<endl;

        if(level1 == level2) 
            return root;

        return level1 > level2 ? l : r;
    }
};