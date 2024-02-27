class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = reduce(matchsticks.begin(), matchsticks.end());
        if(sum % 4 != 0) 
            return false;

        int size = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(0, n, matchsticks, size, size, size, size);
    }

    bool solve(int i, int n, vector<int>& matchsticks, int t, int l, int b, int r) {
        if(i >= n)
            return t == 0 && l == 0 && b == 0 && r == 0;

        if(matchsticks[i] <= t && solve(i+1, n, matchsticks, t - matchsticks[i], l, b, r))
            return true;

        if(matchsticks[i] <= l && solve(i+1, n, matchsticks, t, l - matchsticks[i], b, r))
            return true;
        
        if(matchsticks[i] <= b && solve(i+1, n, matchsticks, t, l, b - matchsticks[i], r))
            return true;

        if(matchsticks[i] <= r && solve(i+1, n, matchsticks, t, l, b, r - matchsticks[i]))
            return true;
        
        return false;
    }
};