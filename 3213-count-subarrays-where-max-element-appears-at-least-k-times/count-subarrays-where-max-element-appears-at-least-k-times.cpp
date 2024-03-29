class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());

        int l = 0, n = nums.size(), freq = 0;
        long long count = 0;

        for(int r=0; r<n; r++) {
            freq += (nums[r] == maxVal);

            while(freq >= k) {
                freq -= (nums[l] == maxVal);
                l++;
            }

            if(freq < k)
                count += (r - l + 1);
        }

        return n * (long long)(n + 1) / 2 - count;
    }
};

/*
k = 2

1   2   3   2   1   3   3
            l
                    r

freq = 1


count = 
count: No. of subarrays with maxVal repeating < k times 

total = n * (n + 1) / 2 subarrays
No. of subarrays with atleast k times = total subarrays - No. of subarrays with maxVal repeating < k times
*/