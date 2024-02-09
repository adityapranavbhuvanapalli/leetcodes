class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n =  nums.size(), maxLen = 1, maxIdx = 0;
        vector<int> parent(n, -1), dp(n, 1), res;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                } 
            }

            if(maxLen < dp[i]) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        // cout<<maxLen<<" "<<maxIdx<<endl;
        // for(const auto& num: parent)
        //     cout<<num<<" ";

        while(maxIdx != -1) {
            res.push_back(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }

        return res;
    }
};