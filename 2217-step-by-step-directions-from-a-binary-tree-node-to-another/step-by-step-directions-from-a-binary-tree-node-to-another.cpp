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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = getLeastCommonAncestor(root, startValue, destValue);

        int depth = getDepth(lca, startValue);
        string source = string(depth - 1, 'U');
        string destination = "";
        getLCAToDest(lca, destination, destValue);

        return  source + destination;
    }

    int getDepth(TreeNode* root, int startValue) {
        if(!root)
            return INT_MAX;
            
        if(root->val == startValue)
            return 1;

        int l = getDepth(root->left, startValue);
        if(l != INT_MAX)
            return 1 + l;
        
        int r = getDepth(root->right, startValue);
        if(r != INT_MAX)
            return 1 + r;

        return INT_MAX;
    }

    bool getLCAToDest(TreeNode* root, string& comb, int destValue) {
        if(!root) 
            return false;
        
        if(root->val == destValue) 
            return true;

        comb.push_back('L');
        if(getLCAToDest(root->left, comb, destValue)) 
            return true; 
        comb.pop_back();
        
        comb.push_back('R');
        if(getLCAToDest(root->right, comb, destValue)) 
            return true;
        comb.pop_back();
        
        return false;
    }

    TreeNode* getLeastCommonAncestor(TreeNode* root, int a, int b) {
        if(!root)
            return nullptr;

        if(root->val == a || root->val == b)
            return root;

        TreeNode* l = getLeastCommonAncestor(root->left, a, b);
        TreeNode* r = getLeastCommonAncestor(root->right, a, b);

        if(l && r) 
            return root;

        if(l)
            return l;

        if(r)
            return r;

        return nullptr;
    }
};

/*
  5
 .   .
 1   2
.   . .
3   6 4

Find Least common ancestor and trace the path from there.
*/