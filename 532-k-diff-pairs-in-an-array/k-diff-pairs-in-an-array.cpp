class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> freq;

        sort(nums.begin(), nums.end());

        for(const auto& num: nums) {
            if((k == 0 && freq[num] == 1) || freq.count(num) == 0)
                count += freq.count(num - k);
            freq[num]++;
        }

        return count;
    }
};

/*
2
3   1   4   1   5
1   1   3   4   5

1   2   2   3   3   3   4   4   0   9   2   3

1 - 2
3 - 1
4 - 1
5 - 1
*/