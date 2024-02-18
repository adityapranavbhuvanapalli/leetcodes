class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [&](auto& l, auto& r) {
            return l.size() == r.size() ? l > r : l.size() > r.size();
        });

        return nums[k - 1];
    }
};