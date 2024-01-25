class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int top, left, diagonal, n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));

        for(int i=0; i<n1; i++) {
            for(int j=0; j<n2; j++) {
                top = (i > 0) ? dp[i-1][j] : 0;
                left = (j > 0) ? dp[i][j-1] : 0;
                diagonal = (i > 0 && j > 0) ? dp[i-1][j-1] : 0;

                dp[i][j] = (text1[i] == text2[j]) ? 1 + diagonal : max(top, left);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }

        return dp[n1-1][n2-1];
    }
};

/*

    a   b   c   d   e
a   1   1   1   1   1
c   1   1   2   2   2   
e   1   1   2   2   3   


    b   s   b   i   n   i   n   m
j   0   0   0   0   0   0   0   0   
m   0   0   0   0   0   0   0   1  
j   0   0   0   0   0   0   0   1
k   0   0   0   0   0   0   0   1
b   1   1   1   1   1   1   1   1
k   1   1   1   1   1   1   1   1
j   1   1   1   1   1   1   1   1
k   1   1   1   1   1   1   1   1
v   1   1   1   1   1   1   1   1
*/