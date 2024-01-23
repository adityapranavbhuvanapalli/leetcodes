class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int dist = 0;
        vector<vector<int>> rowGraph(k+1), colGraph(k+1), res(k, vector<int>(k, 0));
        vector<int> incomingRow(k+1, 0), incomingCol(k+1, 0);
        vector<vector<int>> position(k+1, vector<int>(2, -1));
        queue<int> q;
        
        for(const auto& condition: rowConditions) {
            rowGraph[condition[0]].push_back(condition[1]);
            incomingRow[condition[1]]++;
        }

        for(const auto& condition: colConditions) {
            colGraph[condition[0]].push_back(condition[1]);
            incomingCol[condition[1]]++;
        }

        // Find row priority
        for(int i=1; i<=k; i++) {
            if(incomingRow[i] == 0) {
                q.push(i);
            }
        }

        dist = 0;
        while(q.size()) {
            int cur = q.front();
            q.pop();

            if(position[cur][0] != -1)
                return {};

            position[cur][0] = dist;

            for(const auto& adj: rowGraph[cur]) {
                if(--incomingRow[adj] == 0)
                    q.push(adj);
            }

            dist++;
        }

        // Find col priority
        for(int i=1; i<=k; i++) {
            if(incomingCol[i] == 0) {
                q.push(i);
            }
        }

        dist = 0;
        while(q.size()) {
            int cur = q.front();
            q.pop();

            if(position[cur][1] != -1)
                return {};

            position[cur][1] = dist;

            for(const auto& adj: colGraph[cur]) {
                if(--incomingCol[adj] == 0)
                    q.push(adj);
            }

            dist++;
        }

        for(int i=1; i<=k; i++) {
            if(position[i][0] == -1 || position[i][1] == -1)
                return {};
            // cout<<i<<": "<<position[i][0]<<","<<position[i][1]<<endl;
            res[position[i][0]][position[i][1]] = i;
        }

        return res;
    }
};