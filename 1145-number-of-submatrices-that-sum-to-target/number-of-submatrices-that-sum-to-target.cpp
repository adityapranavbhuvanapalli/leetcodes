class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        int top, left, diagonal;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                top = (i > 0) ? matrix[i-1][j] : 0;
                left = (j > 0) ? matrix[i][j-1] : 0;
                diagonal = (i > 0 && j > 0) ? matrix[i-1][j-1] : 0;

                matrix[i][j] += (top + left - diagonal);
            }
        }

        for(int x1=0; x1<m; x1++) {
            for(int y1=0; y1<n; y1++) {
                for(int x2=0; x2<=x1; x2++) {
                    for(int y2=0; y2<=y1; y2++) {
                        top = (x2 > 0) ? matrix[x2-1][y1] : 0;
                        left = (y2 > 0) ? matrix[x1][y2-1] : 0;
                        diagonal = (x2 > 0 && y2 > 0) ? matrix[x2-1][y2-1] : 0;
                        
                        if(matrix[x1][y1] - top - left + diagonal == target)
                            res++;
                    }
                }
            }
        }

        return res;
    }
};