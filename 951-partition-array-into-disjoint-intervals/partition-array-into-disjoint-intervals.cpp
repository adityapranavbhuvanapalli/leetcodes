class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxSoFar = -1, n = nums.size();
        stack<int> s;

        for(int i=n-1; i>=0; i--) {
            if(!s.size() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }

        for(int i=0; i<n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if(s.size() && s.top() == i)
                s.pop();

            // stack<int> tmp(s);
            // while(tmp.size()) {
            //     cout<<tmp.top()<<"<";
            //     tmp.pop();
            // }
            // cout<<endl;

            if(maxSoFar <= nums[s.top()]) 
                return i+1;
        }

        return n;
    }
};

/*
1   1   1   6   0   12     
*/