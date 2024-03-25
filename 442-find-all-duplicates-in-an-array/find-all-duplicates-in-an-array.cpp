class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0, n = nums.size();
        vector<int> res;

        while(i < n) {
            while(i < n && nums[i] - 1 < n && nums[nums[i] - 1] != nums[i] && nums[i] != i + 1) {
                swap(nums[i], nums[nums[i] - 1]);
            }

            i++;
        }

        for(int i=0; i<n; i++) {
            if(nums[i] != i + 1) 
                res.push_back(nums[i]);
        }

        return res;
    }
};