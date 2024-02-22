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
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root = nullptr;
        stack<TreeNode*> s;
        string cur = "";
        int curTabCount = 0;
        bool addedToStack = false;

        traversal += '-';

        for(const auto& ch: traversal) {
            if(ch != '-') {
                addedToStack = false;
                cur += ch;
                continue;
            }

            // If ch == '-'
            if(addedToStack) {
                curTabCount++;
                continue;
            }

            while(curTabCount < s.size())
                s.pop();
            
            // Add node to tree
            TreeNode* node = new TreeNode(stoi(cur));

            if(s.size()) {
                TreeNode* parent = s.top();
                if(parent->left == nullptr) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            } else {
                root = node;
            }

            s.push(node);
 
            curTabCount = 1;
            cur = "";
            addedToStack = true;
        }

        return root;
    }
};

/*
1-2--3--4-5--6--7

1
    2
        3
        4
    5
        6
        7

1
5
*/