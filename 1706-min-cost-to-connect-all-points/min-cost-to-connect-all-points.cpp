class Solution {
public:
    int minCost = 0, components;
    vector<int> root;

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int n = points.size();
        root.resize(n);
        components = n;
        
        for(int i=0; i<n; i++)
            root[i] = i;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({dist, i, j});
            }
        }

        while(pq.size()) {
            auto top = pq.top();
            pq.pop();

            unite(top[0], top[1], top[2]);
        }   

        return minCost;     
    }
    
    int find(int i) {
        return root[i] = (root[i] == i) ? i : find(root[i]);
    }

    void unite(int cost, int a, int b) {
        int findA = find(a), findB = find(b);

        if(findA != findB) {
            root[max(findA, findB)] = min(findA, findB);
            minCost += cost;
            components--;
        }
    }
};