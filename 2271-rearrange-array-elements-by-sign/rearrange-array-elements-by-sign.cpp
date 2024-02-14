class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int k = 0, n = nums.size();
        vector<int> pos, neg;

        for(const auto& num: nums) {
            auto& array = (num > 0) ? pos : neg;   
            array.push_back(num);
        }

        for(int i=0; i<n/2; i++) {
            nums[k] = pos[i];
            nums[k+1] = neg[i];
            k += 2;
        }

        return nums;
    }
};