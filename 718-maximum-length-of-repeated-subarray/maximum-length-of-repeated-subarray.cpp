class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), res = 0, diagonal;
        vector<vector<int>> dp(n1, vector<int>(n2, 0));

        for(int i=0; i<n1; i++) {
            for(int j=0; j<n2; j++) {
                diagonal = (i > 0 && j > 0) ? dp[i-1][j-1] : 0;
                if(nums1[i] == nums2[j])
                    dp[i][j] = 1 + diagonal;
                
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};

/*
1   2   3   2   1

3   2   1   4   7

    3   2   1   4   7
1   0   0   1   0   0
2   0   1   0   0   0
3   1   0   0   0   0
2   0   2   0   0   0
1   0   0   3   0   0   

    0   0   0   0   0
0   1   1   1   1   1
0   1   2   2   2   2
0   1   2   3   3   3
0   1   2   3   4   4
0   1   2   3   4   5

*/