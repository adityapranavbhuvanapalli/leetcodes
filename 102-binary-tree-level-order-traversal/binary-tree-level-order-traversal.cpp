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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        q.push(root);
        while(q.size()) {
            int sz = q.size();
            res.push_back({});
            while(sz--) {
                auto cur = q.front();
                q.pop();
                
                res.back().push_back(cur->val);
            
                if(cur->left)
                    q.push(cur->left);
                
                if(cur->right)
                    q.push(cur->right);
            }
        }
        
        return res;
    }
};