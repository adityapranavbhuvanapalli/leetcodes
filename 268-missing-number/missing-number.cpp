class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;

        for(const auto& num: nums) {
            sum += num;
        }

        return n * (n + 1) / 2 - sum;
    }
};