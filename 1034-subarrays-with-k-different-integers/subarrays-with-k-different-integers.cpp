class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }

    int solve(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), res = 0, count = 0;
        unordered_map<int, int> freq;

        for(int r=0; r<n; r++) {
            if(freq[nums[r]] == 0)
                count++;
            freq[nums[r]]++;

            while(count > k) {
                freq[nums[l]]--;
                if(freq[nums[l]] == 0)
                    count--;
                l++;
            }

            res += (r - l + 1);
        }

        return res;
    }
};

/*
1   2   1   2   3
l
            r

(No. of subarrays with exactly k) = (No. of subarrays <= k) - (No. of subarrays <= k - 1)
*/