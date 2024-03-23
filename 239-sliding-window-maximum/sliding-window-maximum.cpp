class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        vector<int> res;
        deque<int> dq;

        for(int r=0; r<n; r++) {
            // Check if front of dq is valid or not
            // Insert the current element in the back at correct position
            // Add front to res
            if(r - l + 1 > k) {
                l++;
                while(dq.size() && l > dq.front()) 
                    dq.pop_front();
            }  

            while(dq.size() && nums[dq.back()] < nums[r])
                dq.pop_back();

            dq.push_back(r);

            if(r - l + 1 == k)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

/*
0   1   2   3   4   5   6   7
1   3   -1  -3  5   3   6   7
                    l
                            r

dq:
7
7   

res:
3   3   5   5   6
*/