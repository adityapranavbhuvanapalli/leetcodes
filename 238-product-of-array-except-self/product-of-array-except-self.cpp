class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int tmp = 1;
        for(int i=n-1; i>=0; i--) {
            res[i] = tmp * nums[i];
            tmp = res[i];
        }

        tmp = 1;
        for(int i=0; i<n; i++) {
            nums[i] = tmp * nums[i];
            tmp = nums[i];
        }

        // cout<<"Prefix: ";
        // for(const auto& a: nums)
        //     cout<<a<<" ";
        // cout<<endl;

        
        // cout<<"Suffix: ";
        // for(const auto& a: res)
        //     cout<<a<<" ";
        // cout<<endl;   

        for(int i=0; i<n; i++) {
            int left = (i > 0) ? nums[i - 1] : 1;
            int right = (i < n - 1) ? res[i + 1] : 1;
            res[i] = left * right;
        }

        return res;
    }
};

/*
1   2   3   4

res =   24  24  12  4   (suffix)
nums =  1   2   6   24  (prefix)
            i

res =   24  12  8   6
*/