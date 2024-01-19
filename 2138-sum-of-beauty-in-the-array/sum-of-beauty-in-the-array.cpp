class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int maxSoFar = nums[0], n = nums.size(), beautySum = 0;
        stack<int> s;

        for(int i=n-1; i>0; i--) {
            if(!s.size() || nums[s.top()] > nums[i])
                s.push(i);
        }

        for(int i=1; i<n-1; i++) {
            if(s.size() && s.top() == i)
                s.pop();

            if(maxSoFar < nums[i] && nums[i] < nums[s.top()])
                beautySum += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1])
                beautySum += 1;

            maxSoFar = max(maxSoFar, nums[i]);
        }

        return beautySum;
    }
};
