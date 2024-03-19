class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int res = 0, n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> power(n + 1, 1);

        for(int i=1; i<=n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        for(int i=0; i<n; i++) {
            int val = target - nums[i];

            if(target < 2 * nums[i])
                break;

            int idx = binarySearch(i, n - 1, nums, val);
            int len = idx - i + 1;
            
            res = (res + power[len - 1]) % MOD;
        }

        return res;
    }

    int binarySearch(int l, int r, vector<int>& nums, int val) {
        int mid;

        while(l < r) {
            mid = l + ceil((r - l) / 2.0);

            if(nums[mid] <= val) {
                l = mid;
            } else {
                r = mid - 1;
            }   
        }

        return r;
    }
};

/*
11
3   3   6   8   9
l
            r

2^(len - 1)

3, 33, 36, 38, 336, 338, 368, 3368 - 8
3, 36, 38, 368 - 4
*/