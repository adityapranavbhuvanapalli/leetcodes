class Solution {
public:
    unordered_map<int, int> dp;
    int rob(vector<int>& nums) {
        return calcRobbery(0, nums.size(), nums);
    }

    int calcRobbery(int i, int n, vector<int>& nums) {
        if(i >= n)
            return 0;
        
        if(dp.count(i))
            return dp[i];
        
        int pick = nums[i] + calcRobbery(i+2, n, nums);
        int notpick = calcRobbery(i+1, n, nums);

        return dp[i] = max(pick, notpick);
    }
};