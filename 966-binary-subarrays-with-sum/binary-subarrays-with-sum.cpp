class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixFreq;
        int sum = 0, res = 0;

        for(const auto& num: nums) {
            sum += num;
            if(sum == goal)
                res++;
            
            if(prefixFreq.count(sum - goal) == 1) {
                res += prefixFreq[sum - goal];
            }

            prefixFreq[sum]++;
        }

        return res;
    }
};