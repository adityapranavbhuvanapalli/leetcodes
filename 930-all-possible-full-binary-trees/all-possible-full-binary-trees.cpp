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
    unordered_map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.count(n))
            return dp[n];

        if(n == 1)
            return dp[n] = {new TreeNode(0)};

        vector<TreeNode*> res;
        for(int i=0; i<n; i++) {
            vector<TreeNode*> l = allPossibleFBT(i);
            vector<TreeNode*> r = allPossibleFBT(n - i - 1);

            for(auto& subL: l)
                for(auto& subR: r)
                    res.push_back(new TreeNode(0, subL, subR));
        }

        return dp[n] = res;
    }
};