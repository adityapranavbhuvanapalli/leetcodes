class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size(), longest = 0, lenSoFar = 0;
        int sign = 1;

        if(n <= 1)
            return 0;

        int i = 0;

        // Ignore the starting descent
        while(i < n - 1 && nums[i] >= nums[i + 1])
            i++;

        while(i < n - 1) {
            // Ascent
            while(i < n - 1 && nums[i] < nums[i + 1]) {
                lenSoFar++;
                i++;
            }

            if(i == n - 1)
                return longest;

            if(lenSoFar == 0) {
                i++;
                continue;
            }

            if(nums[i] == nums[i + 1]) {
                while(i < n - 1 && nums[i] == nums[i + 1])
                    i++;

                lenSoFar = 0;
                continue;
            }

            if(i == n - 1)
                return longest;

            // For the peak
            lenSoFar++;

            // Descent
            while(i < n - 1 && nums[i] > nums[i + 1]) {
                lenSoFar++;
                i++;
            }

            longest = max(longest, lenSoFar);
            lenSoFar = 0;
        }

        return longest;
    }
};

/*          
            7
                        5
        4
                3
2                   2
    1

                    i   j

lenSoFar = 3
*/