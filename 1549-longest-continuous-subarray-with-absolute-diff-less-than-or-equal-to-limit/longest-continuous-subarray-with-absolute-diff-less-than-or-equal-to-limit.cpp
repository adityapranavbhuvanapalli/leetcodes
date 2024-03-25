class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, n = nums.size(), res = 0;
        deque<int> maxs, mins;

        for(int r=0; r<n; r++) {
            while(maxs.size() && nums[maxs.back()] <= nums[r])
                maxs.pop_back();
            maxs.push_back(r);

            while(mins.size() && nums[mins.back()] >= nums[r])
                mins.pop_back();
            mins.push_back(r);
            
            while(maxs.size() && mins.size() && nums[maxs.front()] - nums[mins.front()] > limit) {
                l++;

                if(maxs.front() < l)
                    maxs.pop_front();
                if(mins.front() < l)
                    mins.pop_front();
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};

/*
8   2   4   7
0   1   2   3

maxs: 0   3
mins: 
*/