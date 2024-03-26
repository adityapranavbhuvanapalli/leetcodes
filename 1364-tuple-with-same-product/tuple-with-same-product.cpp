class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> freq;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                res += freq[nums[i] * nums[j]];
                freq[nums[i] * nums[j]]++;
            }
        }

        // for(const auto& [k, v]: freq) {
        //     res += v * (v - 1) / 2;
        // }

        return 8 * res;
    }
};

/*
1   2   4   5   10

2 - 1
4 - 1
5 - 1
10 - 2 - 2C2 = 1
8 - 1
20 - 2 - 2C2 = 1
40 - 1
50 - 1

nC2 = n * (n - 1) / 2
*/