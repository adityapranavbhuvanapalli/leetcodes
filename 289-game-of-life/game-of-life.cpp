class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size(), count;
        vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, 
            {1, -1}, {1, 0}, {1, 1}, {0, -1}
        };

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                count = 0;
                for(const auto& [x, y]: dirs) {
                    int X = i + x, Y = j + y;
                    if(!(X>=0 && X<m && Y>=0 && Y<n))
                        continue;

                    if(board[X][Y] > 0)
                        count++; 
                }

                board[i][j] = (board[i][j] == 0) ? -count : (count == 0) ? 1 : count; 
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] <= 0) {
                    if(abs(board[i][j]) == 3)
                        board[i][j] = 1;
                    else 
                        board[i][j] = 0;
                } else {
                    if(board[i][j] < 2 || board[i][j] > 3)
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                }
            }
        }
    }
};


/*
1   0   0   0   0   1
0   0   0   1   1   0
1   0   1   0   1   0
1   0   0   0   1   0
1   1   1   1   0   1
0   1   1   0   1   0
1   0   1   0   1   1
1   0   0   1   1   1
1   1   0   0   0   0
*/