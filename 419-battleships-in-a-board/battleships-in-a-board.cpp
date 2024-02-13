class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), unit = 0, count = 0, adj;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                adj = 0;
                if(board[i][j] == 'X') {
                    adj += (i > 0 && board[i-1][j] == 'X');
                    adj += (j > 0 && board[i][j-1] == 'X');
                    adj += (i < m-1 && board[i+1][j] == 'X');
                    adj += (j < n-1 && board[i][j+1] == 'X');

                    if(adj == 0)
                        unit++;
                    else if(adj == 1)
                        count++;
                }

                // cout<<adj<<" ";
            }
            // cout<<endl;
        }

        return unit + count/2;    
    }
};

/*
XXX.XXX
.XXX..X
......X
.......
*/