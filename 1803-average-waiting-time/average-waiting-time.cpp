class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int i = 0, n = customers.size(), time = customers[0][0];
        double res = 0;

        while(i < n) {
            time += customers[i][1];
            res = res + time - customers[i][0];

            if(i < n - 1 && customers[i+1][0] > time)
                time = customers[i+1][0];

            i++;
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