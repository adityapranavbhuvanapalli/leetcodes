class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> graph(n);    // {adj, meetTime}
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;    // {time, node}
        vector<bool> visited(n, false);

        // Adjacency Graph
        for(const auto& meeting: meetings) {
            graph[meeting[0]].push_back({meeting[1], meeting[2]});
            graph[meeting[1]].push_back({meeting[0], meeting[2]});
        }

        // Dijkstra
        q.push({0, 0});
        q.push({0, firstPerson});
        while(q.size()) {
            auto [time, cur] = q.top();
            q.pop();

            if(visited[cur])
                continue;

            visited[cur] = true;
            res.push_back(cur);

            for(const auto& [adj, meetTime]: graph[cur]) {
                if(meetTime >= time) {
                    q.push({meetTime, adj});
                }
            }
        }

        return res;
    }
};

/*
1 - {2, 5}, {5, 10}
2 - {1, 5}, {3, 8}
*/