class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int count = 0, sum = 0;

        for(const auto& num: nums) {
            sum += num;

            if(sum == k)
                count++;

            if(prefix.count(sum - k) == 1)
                count += prefix[sum - k];

            prefix[sum]++;
        }

        return count;
    }
};

/*
1   2   1   2   1
1   3   4   6   7

1   -1  0
1   0   0
*/