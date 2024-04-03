class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(solve(i, j, board, 0, word))
                    return true;
            }
        }

        return false;
    }

    bool solve(int i, int j, vector<vector<char>>& board, int k, string& word) {
        int m = board.size(), n = board[0].size();
        int wordSize = word.size();

        if(k == wordSize - 1)
            return board[i][j] == word[k];

        if(board[i][j] != word[k])
            return false;

        char tmp = board[i][j];

        board[i][j] = '#';

        if(i > 0 && board[i - 1][j] != '#' && solve(i - 1, j, board, k + 1, word))
            return true;
        if(i < m - 1 && board[i + 1][j] != '#' && solve(i + 1, j, board, k + 1, word))
            return true;
        if(j > 0 && board[i][j - 1] != '#' && solve(i, j - 1, board, k + 1, word))
            return true;
        if(j < n - 1 && board[i][j + 1] != '#' && solve(i, j + 1, board, k + 1, word))
            return true;

        board[i][j] = tmp;

        return false;
    }
};

/*
ABCE
SFCS
ADEE
*/