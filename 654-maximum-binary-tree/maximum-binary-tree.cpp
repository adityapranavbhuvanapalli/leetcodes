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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return createTree(0, nums.size() - 1, nums);
    }

    TreeNode* createTree(int l, int r, vector<int>& nums) {
        if(l > r)
            return nullptr;

        if(l == r)
            return new TreeNode(nums[l]);

        int maxVal = 0, maxIdx = -1;
        for(int i=l; i<=r; i++) {
            if(maxVal < nums[i]) {
                maxIdx = i;
                maxVal = nums[i];
            }
        }

        return new TreeNode(
            maxVal,
            createTree(l, maxIdx - 1, nums),
            createTree(maxIdx + 1, r, nums) 
        );
    }
};