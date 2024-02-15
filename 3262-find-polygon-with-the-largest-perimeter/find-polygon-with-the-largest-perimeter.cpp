class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0, perimeter;
        priority_queue<int> pq;

        for(const auto& num: nums) {
            sum += num;
            pq.push(num);
        }

        while(pq.size() >= 2) {
            int top = pq.top();

            if(sum - top > top)
                return sum;

            sum -= top;
            pq.pop();
        }

        return -1;
    }
};

/*
1   1   2   3   5   12  50
1   2   4   7   12  24

5   5   10
*/