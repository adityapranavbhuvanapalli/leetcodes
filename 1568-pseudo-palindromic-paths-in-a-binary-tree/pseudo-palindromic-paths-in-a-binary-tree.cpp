/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> freq(10, 0);
        dfs(root, freq);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& freq) {
        int oddCount = 0;

        if (!root)
            return;

        freq[root->val]++;

        if (!root->left && !root->right) {
            for (const auto& f : freq)
                oddCount += (f % 2 == 1);

            if (oddCount <= 1)
                res++;

        } else {
            dfs(root->left, freq);
            dfs(root->right, freq);
        }

        freq[root->val]--;
    }
};