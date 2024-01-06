class Solution {
public:
    map<int, int> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> times(n);
        // dp = vector<int>(n, -1);

        for(int i=0; i<n; i++) {
            times[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(times.begin(), times.end());

        return solve(0, n, times);
    }

    int solve(int i, int n, vector<tuple<int, int, int>>& times) {
        if(i >= n)
            return 0;

        if(dp.count(i) == 1)
            return dp[i];

        auto& [starti, endi, profiti] = times[i];

        // Find lower bound of times[i].end
        int l = i+1, r = n-1, mid, next = n;
        while(l <= r) {
            mid = l + (r - l) / 2;
            auto& [start, end, profit] = times[mid];
            if(start < endi) {
                l = mid + 1;
            } else {
                next = min(next, mid);
                r = mid - 1;
            }
        }

        return dp[i] = max(solve(i+1, n, times), profiti + solve(next, n, times));
    }
};