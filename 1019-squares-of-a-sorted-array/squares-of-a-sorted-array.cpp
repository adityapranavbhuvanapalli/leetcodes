class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, n = nums.size(), r = n - 1, idx = n - 1;
        vector<int> res(n);

        while(l <= r) {
            long sqrL = nums[l] * nums[l];
            long sqrR = nums[r] * nums[r];

            if(sqrL > sqrR) {
                res[idx--] = sqrL;
                l++;
            } else {
                res[idx--] = sqrR;
                r--;
            }
        } 

        return res;
    }
};