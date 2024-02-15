class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        
        sort(nums.begin(), nums.end());

        for(const auto& num: nums)
            sum += num;

        for(int i=n-1; i>=0; i--) {
            if(sum - nums[i] > nums[i])
                return sum;

            sum -= nums[i];
        }

        return -1;
    }
};

/*
1   1   2   3   5   12  50
1   2   4   7   12  24

5   5   10
*/