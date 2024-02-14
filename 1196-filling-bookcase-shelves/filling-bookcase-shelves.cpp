class Solution {
public: 
    vector<int> dp;
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        dp = vector<int>(n, -1);
        return solve(0, n, books, shelfWidth);
    }

    int solve(int i, int n, vector<vector<int>>& books, int shelfWidth) {
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int j = i, sum = 0, height = 0, res = INT_MAX;
        while(j < n && sum + books[j][0] <= shelfWidth) {
            height = max(height, books[j][1]);
            sum += books[j][0];
            res = min(res, height + solve(j+1, n, books, shelfWidth));
            j++;
        }

        return dp[i] = res;
    }
};