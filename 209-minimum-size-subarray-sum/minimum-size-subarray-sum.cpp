class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, n = nums.size(), sum = 0, minLen = INT_MAX;

        for(int r=0; r<n; r++) {
            sum += nums[r];

            while(sum >= target) {
                sum -= nums[l];
                minLen = min(minLen, r - l + 1);
                l++;
            }
        }

        while(l < n) {
            sum -= nums[l];
            if(sum >= target)
                minLen = min(minLen, n - l + 1);
            l++;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};