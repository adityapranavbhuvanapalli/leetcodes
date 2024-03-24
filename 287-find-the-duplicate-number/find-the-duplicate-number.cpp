class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) 
            return -1;
    
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};