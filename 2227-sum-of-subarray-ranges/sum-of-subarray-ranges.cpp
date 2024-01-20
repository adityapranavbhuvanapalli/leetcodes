class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        vector<long long> mins(n + 1, 0), maxs(n + 1, 0);
        stack<int> minStack, maxStack;

        for (int i = 0; i < n; i++) {
            // Find sum of mins
            while (minStack.size() && nums[minStack.top()] >= nums[i])
                minStack.pop();

            if (minStack.size()) {
                mins[i] = mins[minStack.top()] + (i - minStack.top()) * (long long)nums[i];
            } else {
                mins[i] = (i + 1) * (long long)nums[i];
            }
            minStack.push(i);

            // Find sum of maxs
            while (maxStack.size() && nums[maxStack.top()] <= nums[i])
                maxStack.pop();

            if (maxStack.size()) {
                maxs[i] = maxs[maxStack.top()] + (i - maxStack.top()) * (long long)nums[i];
            } else {
                maxs[i] = (i + 1) * (long long)nums[i];
            }
            maxStack.push(i);

            // Range is sum of maxs[i] - mins[i]
            res = res + maxs[i] - mins[i];
        }

        return res;
    }
};

/*
i           0   1   2
----------------------
nums        1   2   3
----------------------
minStack    1   2   3   <- top
                1   2
                    1
----------------------
mins        1   1   1
                2   2
                    3
----------------------
maxStack    1   2   3   <- top
----------------------
maxs        1   2   3
                2   3
                    3
----------------------
res =       0   1   3   = 4
(maxs - mins)
*/