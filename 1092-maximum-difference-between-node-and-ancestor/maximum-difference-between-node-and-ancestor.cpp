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
    int res = 0;
    int maxAncestorDiff(TreeNode* root) {
        int minVal, maxVal;
        solve(root, minVal, maxVal);
        return res;
    }

    void solve(TreeNode* root, int& minVal, int& maxVal) {
        if(!root) {
            minVal = INT_MAX;
            maxVal = INT_MIN;
            return;
        }

        if(!root->left && !root->right) {
            minVal = maxVal = root->val;
            cout<<root->val<<" "<<minVal<<", "<<maxVal<<endl;
            return;
        }

        int minL, minR, maxL, maxR;
        solve(root->left, minL, maxL);
        solve(root->right, minR, maxR);

        minVal = min({minL, minR, root->val});
        maxVal = max({maxL, maxR, root->val});
        res = max({res, abs(root->val - minVal), abs(root->val - maxVal)});
    }
};