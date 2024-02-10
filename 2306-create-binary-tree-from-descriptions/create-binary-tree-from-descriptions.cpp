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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> address;
        unordered_map<int, int> incoming;

        for(const auto& desc: descriptions) {
            incoming[desc[1]]++;
            if(incoming.count(desc[0]) == 0)
                incoming[desc[0]] = 0;

            if(address.count(desc[0]) == 0)
                address[desc[0]] = new TreeNode(desc[0]);

            if(address.count(desc[1]) == 0)
                address[desc[1]] = new TreeNode(desc[1]);

            if(desc[2])
                address[desc[0]]->left = address[desc[1]];
            else
                address[desc[0]]->right = address[desc[1]];
        }

        for(const auto& [k, v]: incoming)
            if(v == 0)
                return address[k];

        return nullptr;
    }
};

/*

*/