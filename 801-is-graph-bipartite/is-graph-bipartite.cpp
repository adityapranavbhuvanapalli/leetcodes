class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> group(n, -1);
        for(int i=0; i<n; i++) {
            if(group[i] == -1 && !dfs(i, 0, graph, group))
                return false;
        }

        return true;
    }

    bool dfs(int i, int grp, vector<vector<int>>& graph, vector<int>& group) {
        if(group[i] != -1)
            return group[i] == grp;

        group[i] = grp;

        for(const auto& adj: graph[i]) {
            if(!dfs(adj, 1 - grp, graph, group))
                return false;
        }

        return true;
    }
};