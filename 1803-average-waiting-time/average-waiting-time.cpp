class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int i = 1, n = customers.size(), time = customers[0][0];
        double res = 0;
        queue<int> q;

        q.push(0);
        while(q.size()) {
            int cur = q.front();
            q.pop();
            time += customers[cur][1];
            while(i < n && customers[i][0] <= time) {
                q.push(i);
                i++;
            }

            cout<<cur<<": "<<time - customers[cur][0]<<endl;
            res = res + time - customers[cur][0];

            if(i < n && q.empty()) {
                q.push(i);
                time = customers[i][0];
                i++;
            }
        }

        return res / (double) n;
    }
};

/*
1   2   4
2   5   3

time = 1 + 2 = 3
wait = 3 - 1 = 2
-----------------
5   5   10  20
2   4   3   1

time
14 
wait
2   6   4   

q
2
*/