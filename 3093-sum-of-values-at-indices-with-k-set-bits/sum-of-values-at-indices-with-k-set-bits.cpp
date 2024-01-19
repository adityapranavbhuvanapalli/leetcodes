class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int cur, sum = 0, count, n = nums.size();

        for(int i=0; i<n; i++) {
            cur = i;
            count = 0;
            while(cur) {
                count++;
                cur = (cur & (cur-1));
            }
            
            if(count == k) {
                sum += nums[i];
            }
        }

        return sum;
    }
};