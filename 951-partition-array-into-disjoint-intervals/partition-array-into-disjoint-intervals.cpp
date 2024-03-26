class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        stack<int> s;
        int maxVal = 0, n = nums.size();

        for(int i=n-1; i>0; i--) {
            if(s.empty() || nums[s.top()] > nums[i])
                s.push(i);
        }

        for(int i=0; i<n-1; i++) {
            maxVal = max(maxVal, nums[i]);

            if(s.top() == i)
                s.pop();
            
            if(nums[s.top()] >= maxVal)
                return i + 1;
        }

        return -1;
    }
};

/*
5   0   3   8   6
max       min

5   0   3   8   6
        0   3   6

6   8   3   0   5

6   3   0
*/