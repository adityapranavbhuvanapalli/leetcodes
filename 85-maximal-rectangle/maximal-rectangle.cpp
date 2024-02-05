class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == '0')
                    continue;

                maxArea = max(maxArea, findArea(matrix, i, j, m, n));
            }
        }

        return maxArea;
    }

    int findArea(vector<vector<char>>& matrix, int x, int y, int m, int n) {
        int limit = -1, length = 0, breadth = 0, maxArea = 0;
        for(int i=x; i>=0; i--) {
            breadth = 0;
            for(int j=y; j>limit; j--) {
                if(matrix[i][j] == '1') {
                    breadth++;
                } else {
                    limit = j;
                }
            }
            length++;
            maxArea = max(maxArea, length * breadth);
        }

        return maxArea;
    }
};