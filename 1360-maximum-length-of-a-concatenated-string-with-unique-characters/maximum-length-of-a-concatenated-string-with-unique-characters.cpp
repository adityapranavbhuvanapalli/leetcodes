class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        return solve(0, 0, n, arr);
    }

    int solve(int i, int mask, int n, vector<string>& arr) {
        if(i >= n)
            return 0;

        int notpick = solve(i+1, mask, n, arr);

        for(const auto& ch: arr[i]) {
            if(mask & (1 << (ch - 'a')))
                return notpick;

            mask = mask | (1 << (ch - 'a')); 
        }
        
        int pick = arr[i].size() + solve(i, mask, n, arr);

        return max(pick, notpick);
    }
};


/*
00000000000000000000000
mask | (1<<ch)

2^27

(2^4)^7

8^9
*/