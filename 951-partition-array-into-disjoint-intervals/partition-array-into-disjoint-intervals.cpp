class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size(), maxVal = 0;
        vector<int> mins(n, nums[n - 1]);

        for(int i=n-2; i>=0; i--) {
            mins[i] = min(mins[i + 1], nums[i]);
        }

        for(int i=0; i<n-1; i++) {
            maxVal = max(maxVal, nums[i]);
            if(maxVal <= mins[i + 1])
                return i + 1;
        }

        return 0;
    }
};

/*
5   0   3   8   6
max       min

5   0   3   8   6
        0   3   6


5   0   3   8   6
                6

1   1   0   1
0   0   0   1
1   1   1

*/