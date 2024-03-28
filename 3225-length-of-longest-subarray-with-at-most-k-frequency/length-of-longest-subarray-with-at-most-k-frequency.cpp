class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), count = 0, res = 0;
        unordered_map<int, int> freq;

        for(int r=0; r<n; r++) {
            freq[nums[r]]++;
            if(freq[nums[r]] > k)
                count++;

            while(count > 0) {
                freq[nums[l]]--;
                if(freq[nums[l]] == k)
                    count--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};

/*
k = 2
1   2   3   1   2   3   1   2
l
                        r

1 - 3
2 - 2
3 - 2

k = 2
1   2   1   1   5
    l
            r

1 - 2
2 - 1
*/