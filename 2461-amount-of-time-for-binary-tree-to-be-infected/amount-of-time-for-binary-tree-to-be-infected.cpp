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
    unordered_map<int, vector<int>> graph;
    int amountOfTime(TreeNode* root, int start) {
        unordered_set<int> visited{start}; 
        dfs(root, nullptr);
        return dfs2(start, visited) - 1;
    }

    int dfs2(int src, unordered_set<int>& visited) {
        int maxDepth = 0;
        for(const auto& adj: graph[src]) {
            if(!visited.count(adj)) {
                visited.insert(adj);
                maxDepth = max(maxDepth, dfs2(adj, visited));
                visited.erase(adj);
            }
        }
        return 1 + maxDepth;
    }

    void dfs(TreeNode* root, TreeNode* parent) {
        if(!root)
            return;

        if(parent)
            graph[root->val].push_back(parent->val);
        
        if(root->left)
            graph[root->val].push_back(root->left->val);

        if(root->right)
            graph[root->val].push_back(root->right->val);


        dfs(root->left, root);
        dfs(root->right, root);
    }
};