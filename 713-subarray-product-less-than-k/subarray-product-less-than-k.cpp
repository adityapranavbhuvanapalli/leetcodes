class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, n = nums.size();
        int prefix = 1, count = 0;

        for(int r=0; r<n; r++) {
            prefix *= nums[r];

            while(l<r && prefix >= k) {
                prefix /= nums[l];
                l++;
            }
            
            if(prefix < k)
                count += (r - l + 1);
        }

        return count;
    }
};

/*
a   b   c   d   e   f   g   h
    l
                r

n(n+1)/2
1 + 2 + 3 + ... + n
*/