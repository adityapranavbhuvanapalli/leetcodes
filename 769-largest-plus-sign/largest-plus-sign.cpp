class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int res = 0;
        vector<vector<int>> LR(n, vector<int>(n, 1));

        for(const auto& mine: mines) {
            LR[mine[0]][mine[1]] = 0;
        }

        vector<vector<int>> RL = LR, TB = LR, BT = LR;

        for(int i=0; i<n; i++) {
            for(int j=1; j<n; j++) {
                if(LR[i][j] > 0) 
                    LR[i][j] += LR[i][j-1];

                if(RL[i][n - 1 - j] > 0)
                    RL[i][n - 1 - j] += RL[i][n - j];

                if(TB[j][i] > 0)
                    TB[j][i] += TB[j-1][i];

                if(BT[n - 1 - j][i] > 0)
                    BT[n - 1 - j][i] += BT[n - j][i];
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                res = max(res, min({LR[i][j], RL[i][j], TB[i][j], BT[i][j]}));
            }
        }

        return res;
    }
};

/*

1   1   1   1   1
1   0   1   1   1
1   1   1   1   0
1   1   1   1   1
1   1   0   1   1

LR
1   2   3   4   5
1   0   1   2   3
1   2   3   4   0
1   2   3   4   5
1   2   0   1   2

TB
1   1   1   1   1
2   0   2   2   2
3   1   3   3   0
4   2   4   4   1
5   3   0   5   2

RL
5   4   3   2   1
1   0   3   2   1
4   3   2   1   0
5   4   3   2   1
2   1   0   2   1

BT
5   1   4   5   2
4   0   3   4   1
3   3   2   3   0
2   2   1   2   2
1   1   0   1   1

len = n/2


5x5
3x3x9
2x2 - 2
*/