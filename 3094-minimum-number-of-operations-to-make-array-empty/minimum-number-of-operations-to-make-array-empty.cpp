class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        unordered_map<int, int> freq;

        for (const auto& num : nums) {
            freq[num]++;
        }

        for (const auto& [k, v] : freq) {
            if (v == 1)
                return -1;

            ops += ((v+2) / 3);
        }

        return ops;
    }
};
