class Solution {
public:
    long maxProduct = 0;
    unordered_map<int, int> freq;
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> graph(n);

        for(int i=1; i<n; i++) {
            graph[parents[i]].push_back(i);
        }

        dfs(0, n, graph, parents);
        return freq[maxProduct];
    }

    long dfs(int root, int n, vector<vector<int>>& graph, vector<int>& parent) {
        long product = 1, length, sum = 0;
        for(const auto& adj: graph[root]) {
            if(adj == parent[root])
                continue;   
            
            length = dfs(adj, n, graph, parent);
            sum += length;
            
            if(length != 0)
                product *= length;
        }

        if(n - sum - 1 != 0)
            product *= (n - sum - 1);

        freq[product]++;

        maxProduct = max(maxProduct, product);

        return 1 + sum;
    }
};

/*
0 - 2
1 - 1
2 - 3
3 - 1
4 - 1

0 - 2, 4
1 - 2
2 - 0, 3
3 - 2
4 - 0

-1  2   0   2   0

0   2   1   2   1



            4           2
    3           1       1
1       1               0
*/