class Solution {
public:
    int sum = 0;
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> comb;
        backtrack(0, n, nums, comb);
        return sum;
    }

    void backtrack(int start, int n, vector<int>& nums, vector<int>& comb) {
        int xorVal = 0;
        for(const auto& num: comb)
            xorVal = xorVal ^ num; 
        
        sum += xorVal;

        for(int i=start; i<n; i++) {
            comb.push_back(nums[i]);
            backtrack(i + 1, n, nums, comb);
            comb.pop_back();
        }
    }
};