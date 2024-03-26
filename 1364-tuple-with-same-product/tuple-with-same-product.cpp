class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size(), res = 0;
        unordered_map<int, int> freq;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int prod = nums[i] * nums[j];
                res += freq[prod];
                freq[prod]++;
            }
        }

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