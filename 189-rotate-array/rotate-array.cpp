class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q;
        k = k % n;
        
        for(auto& num: nums) {
            q.push(num);

            if(q.size() > k) {
                num = q.front();
                q.pop();
            }
        }

        for(int i=0; i<k; i++) {
            nums[i] = q.front();
            q.pop();
        }
    }
};

/*
3

1   2   3   4   5   6   7
1   2   3   1   2   3   4

1   2   3   4              5    6   7


5   6   7   1   2   3   4
4   3   2   1               7   6   5
*/