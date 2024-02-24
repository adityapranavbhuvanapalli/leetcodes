class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> graph(n);
        vector<int> res;
        vector<bool> visited(n, false);

        for(const auto& meeting: meetings) {
            graph[meeting[0]].push_back({meeting[1], meeting[2]});
            graph[meeting[1]].push_back({meeting[0], meeting[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        pq.push({0, firstPerson});
        while(pq.size()) {
            auto [cost, cur] = pq.top();
            pq.pop();

            if(visited[cur])
                continue;

            visited[cur] = true;
            res.push_back(cur);

            for(const auto& [adj, time]: graph[cur]) {
                if(!visited[adj] && time >= cost) {
                    pq.push({time, adj});
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};

/*
1 - {2, 5}, {5, 10}
2 - {1, 5}, {3, 8}
*/