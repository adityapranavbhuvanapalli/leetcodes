class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int val = 0, count = 0;
        for (const auto& num : nums)
            val = val ^ num;

        val = val ^ k;
        
        while (val) {
            count++;
            val = val & (val - 1);
        }

        return count;
    }
};