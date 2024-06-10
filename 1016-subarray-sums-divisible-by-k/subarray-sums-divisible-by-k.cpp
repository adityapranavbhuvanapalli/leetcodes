class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> rem(k, 0);
        int sum = 0, res = 0;

        rem[0] = 1;
        for (auto& num : nums) {
            sum += num;

            if (sum % k < 0)
                rem[k + sum % k]++;
            else
                rem[sum % k]++;
        }

        for (auto& r : rem)
            res += (r * (r - 1));

        return res / 2;
    }
};