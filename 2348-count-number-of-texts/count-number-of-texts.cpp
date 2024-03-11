class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> dp;
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        dp = vector<int>(n, -1);
        return solve(0, n, pressedKeys);
    }

    int solve(int i, int n, string& pressedKeys) {
        if(i >= n)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        int sum = 0;
        int sz = 3 + (pressedKeys[i] == '7' || pressedKeys[i] == '9');

        for(int j=0; j < sz && i + j < n && pressedKeys[i + j] == pressedKeys[i]; j++)
            sum = (sum + solve(i + j + 1, n, pressedKeys)) % MOD;

        return dp[i] = sum;
    }
};

/*
2
    2
        2
            3
                3(aaadd)
            33(aaae)
    22
        3   
            3(abdd)
        33(abe)
22  
    2
        3
            3(badd)
        33(bae)
222
    3
        3(cdd)
    33(ce)
*/