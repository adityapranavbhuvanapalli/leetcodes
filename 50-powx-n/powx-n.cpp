class Solution {
public:
    unordered_map<int, double> dp;  
    double myPow(double x, int n) {
        bool isPositive = (n>=0);
        double res = calc(x, abs((long)n));
        return isPositive ? res : 1.0/res;
    }
    double calc(double x, long n) {
        if(n == 0 || x == 1)
            return 1;

        if(dp.count(n))
            return dp[n];

        if(n%2 == 0)
            dp[n] = calc(x, n/2) * calc(x, n/2);
        else
            dp[n] = x * calc(x, n/2) * calc(x, n/2);
        
        return dp[n];
    }
};