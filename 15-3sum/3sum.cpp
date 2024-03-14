class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        while(i < n - 2) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if(sum < 0) {
                    l++;
                } else if(sum > 0) {
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while(l < r && nums[l] == nums[l - 1])
                        l++;
                    
                    while(l < r && nums[r] == nums[r + 1])
                        r--;
                }
            } 
            i++;

            while(i < n - 2 && nums[i] == nums[i - 1])
                i++; 
        }

        return res;
    }
};

/*
-1  0   1   2   -1  -4

-4  -1  -1  -1  0   1   2
            i
                l      
                        r
*/