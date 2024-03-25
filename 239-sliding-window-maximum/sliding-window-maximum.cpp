class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        vector<int> res;
        deque<int> dq;

        for(int r=0; r<n; r++) {
            while(dq.size() && nums[dq.back()] < nums[r])
                dq.pop_back();

            dq.push_back(r);

            if(r - l + 1 > k) {
                l++;
                if(dq.front() < l)
                    dq.pop_front();
            }

            if(r - l + 1 == k)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

/*
1   3   -1  -3  2   3   6   7
        l
                r   

dq: 
2
*/