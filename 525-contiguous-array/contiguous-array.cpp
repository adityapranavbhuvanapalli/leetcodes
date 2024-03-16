class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, n = nums.size(), maxLen = 0;
        unordered_map<int, int> firstOccurence;
        firstOccurence[0] = -1;

        for(int i=0; i<n; i++) {
            if(nums[i] == 1) {
                sum++;
            } else {
                sum--;
            }

            if(firstOccurence.count(sum) == 1) {
                maxLen = max(maxLen, i - firstOccurence[sum]);
            } else {
                firstOccurence[sum] = i;
            }
        }

        return maxLen;
    }
};

/*
1   0   0   0   1   0   1   0
1   0   -1  -2  -1  -2  -1  -2 
0   1   2   3   4   5   6   7
*/