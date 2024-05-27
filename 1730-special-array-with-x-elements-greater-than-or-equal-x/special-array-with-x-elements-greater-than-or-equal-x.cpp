class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), greater<int>());

        if(nums[n - 1] >= n)
            return n;

        for(int i=1; i<n; i++) {
            if(nums[i - 1] >= i && i > nums[i])
                return i;
        }

        return -1;
    }
};

/*
3   5
*/