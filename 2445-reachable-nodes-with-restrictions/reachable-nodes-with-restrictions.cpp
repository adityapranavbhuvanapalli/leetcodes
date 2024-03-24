class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int count = 0;
        queue<int> q;
        vector<vector<int>> graph(n);
        unordered_set<int> visited{0};
        unordered_set<int> restrictedSet(restricted.begin(), restricted.end());

        for(const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        q.push(0);
        while(q.size()) {
            int cur = q.front();
            q.pop();

            count++;

            for(const auto& adj: graph[cur]) {
                if(restrictedSet.count(adj) == 0 && visited.insert(adj).second)
                    q.push(adj);
            }
        }

        return count;
    }
};