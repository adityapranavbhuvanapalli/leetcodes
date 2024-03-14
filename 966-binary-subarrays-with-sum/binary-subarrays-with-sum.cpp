class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), l = 0, r = 0, res = 0, sum = 0, count = 0;
        
        while(r < n) {
            if(nums[r] == 1) {
                sum++;
                count = 0;
            }

            while(l <= r && sum >= goal) {
                if(sum == goal)
                    count++;
                sum -= nums[l++];
            }

            res += count;
            r++;
        }

        return res;
    }
};

/*
sum = 2

1   0   1   0   1
1   0

*/