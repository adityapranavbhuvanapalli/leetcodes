class Solution {
public:
    int dp[2000][2000];
    int minCut(string s) {
        int n = s.size(), count = 0, cur, sz;
        vector<bool> visited(n, false);
        queue<int> q;
        memset(dp, -1, sizeof(dp));
        
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                checkPalindrome(i, j, s);
            }
        }

        q.push(0);
        while(q.size()) {
            sz = q.size();
            while(sz--) {
                cur = q.front();
                q.pop();

                if(cur == n)
                    return count - 1;

                for(int j=cur; j<n; j++) {
                    if(dp[cur][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        q.push(j + 1);
                    }
                }
            }
            count++;
        }

        return 0;
    }

    bool checkPalindrome(int l, int r, string& s) {
        if(l >= r)
            return dp[l][r] = true;

        if(dp[l][r] != -1) 
            return dp[l][r];

        return dp[l][r] = (s[l] == s[r]) && checkPalindrome(l+1, r-1, s);
    }
};

/*
aaab
i
  j
*/