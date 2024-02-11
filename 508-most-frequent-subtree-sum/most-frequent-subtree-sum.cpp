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
    unordered_map<int, int> sumsFreq;
    int maxFreq = 0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;

        sum(root);

        for(const auto& [k, v]: sumsFreq) {
            if(v == maxFreq) 
                res.push_back(k);
        }

        return res;
    }

    int sum(TreeNode* root) {
        if(!root)
            return 0;

        int l = sum(root->left);
        int r = sum(root->right);
        int rootSum = l + r + root->val;
        sumsFreq[rootSum]++;
        if(maxFreq < sumsFreq[rootSum])
            maxFreq = sumsFreq[rootSum];
        return l + r + root->val;
    }
};