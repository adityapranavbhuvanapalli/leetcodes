class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int prev = 0, maxTime = 0, maxId;

        for(const auto& log: logs) {
            if(maxTime < log[1] - prev) {
                maxTime = log[1] - prev;
                maxId = log[0];
            } else if(maxTime == log[1] - prev) {
                maxId = min(maxId, log[0]);
            }

            prev = log[1];
        }

        return maxId;
    }
};