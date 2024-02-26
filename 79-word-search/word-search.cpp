class Solution {
public:
    int m, n, len; // m - noOfRows, n - noOfCols, len - wordLength
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), len = word.size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(search(board, i, j, word, 0))
                    return true;
        
        return false;
    }

    bool search(vector<vector<char>>& board, int i, int j, string& word, int k) {
        if(k == len - 1)
            return board[i][j] == word[k];

        if(board[i][j] != word[k])
            return false;

        // Backtrack
        char ch = board[i][j];
        board[i][j] = '#';
        if(i > 0 && search(board, i-1, j, word, k+1))
            return true;
        if(j > 0 && search(board, i, j-1, word, k+1)) 
            return true;
        if(i < m-1 && search(board, i+1, j, word, k+1)) 
            return true;
        if(j < n-1 && search(board, i, j+1, word, k+1))
            return true;
        board[i][j] = ch;

        return false;
    }
};