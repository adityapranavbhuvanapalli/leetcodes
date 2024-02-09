class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, n = nums.size(), l, r, sum;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        while(i < n) {
            l = i + 1, r = n - 1;

            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];

                if(sum > 0) {
                    r--;
                    continue;
                } 

                if(sum < 0) {
                    l++;
                    continue;
                }

                res.push_back({nums[i], nums[l], nums[r]});
                l++, r--;

                while(l < r && nums[l] == nums[l-1]) 
                    l++;

                while(l < r && nums[r] == nums[r+1])
                    r--;
            }

            i++;
            while(i < n && nums[i] == nums[i-1])
                i++;
        }
        
        return res;
    }
};