class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;

        int prev2 = 0, prev1 = 1, val;

        for (int i = 1; i <= n; i++) {
            val = prev1 + prev2;
            prev2 = prev1;
            prev1 = val;
        }

        return val;
    }
};