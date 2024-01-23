class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 2, n = nums.size();

        if(n == 1)
            return n;

        for(int r=2; r<n; r++) {
            if(nums[r] != nums[l-2]) {
                nums[l++] = nums[r];
            }
        }

        return l;
    }
};