class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long ans = 0, n = nums.size(), diff;
		vector<unordered_map<long, long>> dp(n);
		for (int i=0; i<n; i++) {
			for (int j=0; j<i; j++) {
				diff = (long)nums[i] - nums[j];
				dp[i][diff]++;
				if (dp[j].count(diff)) {
					dp[i][diff] += dp[j][diff];
					ans += dp[j][diff];
				}
			}
		}
		return ans;
    }
};