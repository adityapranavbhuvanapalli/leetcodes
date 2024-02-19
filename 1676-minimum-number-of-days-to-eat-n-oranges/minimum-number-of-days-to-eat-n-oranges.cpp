class Solution {
public:
    int minDays(int n) {
        queue<int> q;
        int count = 0;
        vector<bool> visited(n + 1, false);
        q.push(n);
        visited[n] = true;

        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                int num = q.front();
                q.pop();

                if(num == 0)
                    return count;

                if(visited[num - 1] == 0) {
                    q.push(num - 1);
                    visited[num - 1] = true;
                }

                if(num % 2 == 0 && visited[num / 2] == 0) {
                    q.push(num / 2);
                    visited[num / 2] = true;
                }

                if(num % 3 == 0 && visited[num / 3] == 0) {
                    q.push(num / 3);
                    visited[num / 3] = true;
                }
            }
            count++;
        }

        return count;
    }
};

/*
10  9   3   1   0
6   3   1   0

8

0 - 0
1 - 1
2 - 1 + min(dp[1], dp[1]) = 2
3 - 1 + min(dp[2], dp[1]) = 2
4 - 1 + min(dp[3], dp[2]) = 3
5 - 1 + dp[4] = 4
6 - 1 + min(dp[5], dp[2], dp[3]) = 3
7 - 1 + dp[6] = 4
8 - 1 + min(dp[7], dp[4]) = 4
*/