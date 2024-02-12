class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int res = 0;
        vector<vector<pair<int, int>>> graph(n+1);
        vector<int> dist(n+1, INT_MAX);

        // Adjacency Graph
        for(const auto& time: times) {
            graph[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(k);
        dist[k] = 0;
        while(pq.size()) {
            int cur = pq.top();
            pq.pop();
            
            for(const auto& [adj, d]: graph[cur]) {
                if(dist[adj] > dist[cur] + d) {
                    dist[adj] = dist[cur] + d;
                    pq.push(adj);
                }
            }
        }

        for(int i=1; i<=n; i++)
            res = max(res, dist[i]);

        return res == INT_MAX ? -1 : res;
    }
};