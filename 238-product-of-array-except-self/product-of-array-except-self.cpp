class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> res(n);

        int tmp = 1;
        for(int i=0; i<n; i++) {
            prefix[i] = tmp * nums[i];
            tmp = prefix[i];
        }

        tmp = 1;
        for(int i=n-1; i>=0; i--) {
            suffix[i] = tmp * nums[i];
            tmp = suffix[i];
        }

        for(int i=0; i<n; i++) {
            int left = (i > 0) ? prefix[i - 1] : 1;
            int right = (i < n - 1) ? suffix[i + 1] : 1;
            res[i] = left * right;
        }

        return res;
    }
};