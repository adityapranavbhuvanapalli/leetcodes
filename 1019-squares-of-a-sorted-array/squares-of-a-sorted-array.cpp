class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1, idx = n-1;
        vector<int> res(n);

        while(l <= r) {
            int sqrL = nums[l] * nums[l];
            int sqrR = nums[r] * nums[r];

            res[idx--] = max(sqrL, sqrR);

            (sqrL < sqrR) ? r-- : l++;
        }

        return res;
    }
};


/*
l = 0, r = 4
-4  -1  0   3   10
    l           
        r

0   1   9   16  100
-   -   -   -   -
*/