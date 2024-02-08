class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), major = nums[0], maxCount = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] == major) {
                maxCount++;
                continue;
            } 

            maxCount--;

            if(maxCount < 0) {
                major = nums[i];
                maxCount = 1;
            }
        }

        return major;
    }
};