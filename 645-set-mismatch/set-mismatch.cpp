class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0, n = nums.size();

        while (i < n) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);

            i++;
        }

        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return {nums[i], i + 1};

        return {};
    }
};