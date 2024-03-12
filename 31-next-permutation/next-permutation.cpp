class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = n - 2;

        while(pivot >= 0 && nums[pivot] >= nums[pivot + 1])
            pivot--;

        if(pivot != -1) {
            int next = n - 1;
            while(next > pivot && nums[next] <= nums[pivot]) {
                next--;
            }
            swap(nums[pivot], nums[next]);
        }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

/*
1   2   3
1   3   2
p
*/