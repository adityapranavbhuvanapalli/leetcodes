class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        for(int i=0; i<m; i++) {
            // Sort each diagonal in the vertical 
            int j = 0;
            vector<int> diagonal;
            while(i + j < m && j < n) {
                diagonal.push_back(mat[i + j][j]);
                j++;
            }

            sort(diagonal.begin(), diagonal.end());

            j = 0;
            int k = 0;
            while(i + j < m && j < n) {
                mat[i + j][j] = diagonal[k++];
                j++;
            }
        }

        for(int j=1; j<n; j++) {
            // Sort each diagonal in the horizontal 
            int i = 0;
            vector<int> diagonal;

            while(i < m && j + i < n) {
                diagonal.push_back(mat[i][i + j]);
                i++;
            }

            sort(diagonal.begin(), diagonal.end());

            i = 0;
            int k = 0;
            while(i < m && i + j < n) {
                mat[i][i + j] = diagonal[k++];
                i++;
            }
        }

        return mat;
    }
};

/*
3   3   1   1  
2   2   1   2
1   1   1   2
*/  