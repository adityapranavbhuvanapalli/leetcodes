class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size(), key;
        unordered_map<int, int> remainders;

        for (auto& num : nums) {
            num = num % value;
            key = num < 0 ? value + num : num;
            num = key + remainders[key] * value;
            remainders[key]++;
        }

        // First missing non - negative
        for (int i = 0; i < n; i++) {
            while (i < n && nums[i] < n && nums[i] != i &&
                   nums[nums[i]] != nums[i]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i)
                return i;
        }

        return n;
    }
};