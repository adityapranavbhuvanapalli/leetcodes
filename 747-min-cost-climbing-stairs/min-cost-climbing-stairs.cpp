class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int a = cost[0], b = cost[1], c;
        for(int i=2; i<n; i++) {
            c = cost[i] + min(a, b);
            a = b;
            b = c;
        }

        return min(a, b);
    }
};