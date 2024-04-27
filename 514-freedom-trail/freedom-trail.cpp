class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int nRing = ring.size(), nKey = key.size();
        vector<vector<int>> pos(26);
        vector<vector<int>> dp(nRing, vector<int>(nKey, -1));

        for(int i=0; i<nRing; i++) {
            pos[ring[i] - 'a'].push_back(i);
        }
        
        return solve(0, 0, nRing, nKey, key, pos, dp);
    }

    int solve(int cur, int i, int nRing, int nKey, string& key, vector<vector<int>>& pos, vector<vector<int>>& dp) {
        if(i >= nKey)
            return 0;

        if(dp[cur][i] != -1)
            return dp[cur][i];

        int minVal = INT_MAX;
        for(const auto& j: pos[key[i] - 'a']) {
            int dist = min(abs(j - cur), nRing - abs(j - cur));
            minVal = min(minVal, 1 + dist + solve(j, i + 1, nRing, nKey, key, pos, dp));
        }

        return dp[cur][i] = minVal;
    }
};

/*
GODDING
0123456

G - 0,6
O - 1
D - 2,3
I - 4
N - 5

*/