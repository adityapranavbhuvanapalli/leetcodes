class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int pos = 0, neg = 1;
        for(const auto& num: nums) {
            auto& idx = (num > 0) ? pos : neg;
            res[idx] = num;
            idx += 2;
        }

        return res;
    }
};