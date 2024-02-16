class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), wordSize = word.size();
        vector<vector<int>> vertical(m, vector<int>(n, 0)), horizontal(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '#')
                    continue;

                int top = (i > 0) ? vertical[i-1][j] : 0;
                int left = (j > 0) ? horizontal[i][j-1] : 0;

                vertical[i][j] = 1 + top;
                horizontal[i][j] = 1 + left;

                if(vertical[i][j] == wordSize && (i == m - 1 || board[i+1][j] == '#')) {
                    if(checkVertical(i, j, m, n, board, word))
                        return true;
                } 

                if(horizontal[i][j] == wordSize && (j == n - 1 || board[i][j+1] == '#')) {
                    if(checkHorizontal(i, j, m, n, board, word))
                        return true;
                } 
            }
        }

        return false;
    }

    bool checkVertical(int x, int y, int m, int n, vector<vector<char>>& board, string& word) {
        int i, wordSize = word.size();
        int x1;
        // Check vertical forward
        x1 = x;
        for(i=0; i<wordSize; i++) {
            if(board[x1][y] != ' ' && board[x1][y] != word[i])
                break;
                
            x1--;
        }

        if(i == wordSize)
            return true;

        // Check vertical backward
        x1 = x;
        for(i=0; i<wordSize; i++) {
            if(board[x1][y] != ' ' && board[x1][y] != word[wordSize - i - 1])
                break;
                
            x1--;
        }

        if(i == wordSize)
            return true;

        return false;
    }

    bool checkHorizontal(int x, int y, int m, int n, vector<vector<char>>& board, string& word) {
        int i, wordSize = word.size();
        int y1;

        // Check vertical forward
        y1 = y;
        for(i=0; i<wordSize; i++) {
            if(board[x][y1] != ' ' && board[x][y1] != word[i])
                break;
                
            y1--;
        }

        if(i == wordSize)
            return true;

        // Check vertical backward
        y1 = y;
        for(i=0; i<wordSize; i++) {
            if(board[x][y1] != ' ' && board[x][y1] != word[wordSize - i - 1])
                break;
                
            y1--;
        }

        if(i == wordSize)
            return true;

        return false;
    }
};

/*
vertical:
0   1   0
1   2   0
0   3   1

horizontal:
0   1   0
1   2   0
0   1   2
*/