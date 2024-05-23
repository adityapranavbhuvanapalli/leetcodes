class Solution {
public:
    int res = 0;
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> comb;
        
        sort(nums.begin(), nums.end());
        
        backtrack(0, n, nums, k, comb);
        return res - 1;
    }

    void backtrack(int start, int n, vector<int>& nums, int k, vector<int>& comb) {
        res++;

        for(int i=start; i<n; i++) {
            if(binarysearch(comb, nums[i] - k))
                continue;
            
            comb.push_back(nums[i]);
            backtrack(i+1, n, nums, k, comb);
            comb.pop_back();
        }
    }

    bool binarysearch(vector<int>& comb, int val) {
        int l = 0, r = comb.size() - 1, mid;

        while(l <= r) {
            mid = l + (r - l) / 2;
            if(comb[mid] == val)
                return true;
            
            if(comb[mid] < val)
                l = mid + 1;
            else 
                r = mid - 1;
        } 

        return false;
    }
};