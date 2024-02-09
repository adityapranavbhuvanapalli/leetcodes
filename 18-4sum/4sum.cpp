class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i = 0, j, n = nums.size(), l, r;
        long sum;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        while(i < n) {
            j = i + 1;
            while(j < n) {
                l = j + 1, r = n - 1;

                while(l < r) {
                    sum = (long)nums[i] + nums[j] + nums[l] + nums[r];

                    if(sum > target) {
                        r--;
                        continue;
                    } 

                    if(sum < target) {
                        l++;
                        continue;
                    }

                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++, r--;

                    while(l < r && nums[l] == nums[l-1]) 
                        l++;

                    while(l < r && nums[r] == nums[r+1])
                        r--;
                }

                j++;
                while(j < n && nums[j] == nums[j-1])
                    j++;
            }

            i++;
            while(i < n && nums[i] == nums[i-1])
                i++;
        }
        
        return res;
    }
};