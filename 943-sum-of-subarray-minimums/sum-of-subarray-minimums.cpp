class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> dp(n + 1, 0);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (s.size() && arr[s.top()] >= arr[i])
                s.pop();

            if (s.size()) {
                dp[i] = dp[s.top()] + (i - s.top()) * arr[i];
            } else {
                dp[i] = (i + 1) * arr[i];
            }

            res = (res + dp[i]) % MOD;

            s.push(i);
        }

        return res;
    }
};

/*
i   0   1   2   3   4
---------------------
arr 11  81  94  43  3
---------------------
s   11  81  94  43  3   <- top
        11  81  11
            11
---------------------
dp  11  11  11  11  3
        81  81  43  3
            94  43  3
                43  3
                    3
---------------------
res 11  92  186 140 15 = 444
*/