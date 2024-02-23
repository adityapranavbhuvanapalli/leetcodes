class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        int nEdges = edges.size();

        vector<double> probs(n, 0);
        priority_queue<pair<double, int>> pq;

        // Make adjacency graph
        for(int i=0; i<nEdges; i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        pq.push({1, start});
        probs[start] = 1;
        while(pq.size()) {
            auto [prob, cur] = pq.top();
            pq.pop();

           for(const auto& [adj, cost]: graph[cur]) {
               if(prob * cost > probs[adj]) {
                   probs[adj] = prob * cost;
                   pq.push({probs[adj], adj});
               }
           }

        }

        return probs[end];
    }
};

/*
012
*/