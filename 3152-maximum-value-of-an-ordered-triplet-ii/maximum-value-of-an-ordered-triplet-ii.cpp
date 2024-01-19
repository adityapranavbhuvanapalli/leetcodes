class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxSoFar = nums[0], n = nums.size();
        long long maxVal = 0;
        stack<int> s;

        for(int i=n-1; i>0; i--) {
            if(!s.size() || nums[s.top()] < nums[i])
                s.push(i);
        }

        for(int j=1; j<n-1; j++) {
            if(s.size() && s.top() == j)
                s.pop();

            maxVal = max(maxVal, (long long)(maxSoFar - nums[j]) * nums[s.top()]);
            maxSoFar = max(maxSoFar, nums[j]);
        }

        return maxVal;
    }
};

/*
14   12  1   2   7

* Maintain a maxSoFar from the left
* Maintain a maxVal from i to k
*/