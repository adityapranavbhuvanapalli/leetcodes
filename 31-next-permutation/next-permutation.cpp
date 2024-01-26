class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index, n = nums.size();

        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }

        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

         for(int i=n-1; i>index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
         
        reverse(nums.begin() + index + 1, nums.end());
    }
};

/*
1   2   3   4
1   2   4   3
1   3   2   4
1   3   4   2
1   4   2   3
.
.
.
4   3   2   1
*/