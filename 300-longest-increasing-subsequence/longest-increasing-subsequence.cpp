class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxVal = 0, n = nums.size();
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxVal = max(maxVal, dp[i]);
        }

        return maxVal;
    }
};