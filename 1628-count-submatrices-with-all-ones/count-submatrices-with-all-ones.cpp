class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), count = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                count += solve(i, j, mat);
            }
        }
        
        return count;
    }
    
    int solve(int x, int y, vector<vector<int>>& mat) {
        int count = 0, left = -1;
        
        for(int i=x; i>=0; i--) {
            for(int j=y; j>left; j--) {
                if(mat[i][j] == 1)
                    count++;
                else
                    left = j;
            }
        }
        
        return count;
    }
};

/*
1   0   1
1   1   0
1   1   0

*/