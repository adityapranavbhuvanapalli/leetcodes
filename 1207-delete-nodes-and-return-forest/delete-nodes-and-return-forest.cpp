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
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> eraseSet;

        for(const auto& e: to_delete) {
            eraseSet.insert(e);
        }

        // Separate the trees
        bool remove = separateTrees(root, eraseSet);       

        if(!remove)
            res.push_back(root);

        return res;
    }

    bool separateTrees(TreeNode* root, unordered_set<int>& eraseSet) {
        if(!root)
            return false; 

        bool removeL = separateTrees(root->left, eraseSet);
        bool removeR = separateTrees(root->right, eraseSet);

        if(removeL)
            root->left = nullptr;
        
        if(removeR)
            root->right = nullptr;

        if(eraseSet.count(root->val) == 1) {
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            return true;
        }

        return false;
    }
};