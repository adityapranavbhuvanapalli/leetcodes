class Solution {
public:
    unordered_map<int, int> dp;
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i=lo; i<=hi; i++) {
            pq.push({solve(i), i});
            if(pq.size() > k)
                pq.pop();
        }

        return pq.top().second;
    }

    int solve(int num) {
        if(num == 1)
            return dp[num] = 0;

        if(dp.count(num) == 1)
            return dp[num];

        if(num & 1)
            return dp[num] = 1 + solve(num * 3 + 1);
        
        return dp[num] = 1 + solve(num / 2);
    } 
};

/*
1 -> 0
2 - 1 -> 1
3 - 10 - 5 - 16 - 8 - 4 - 2 - 1 -> 7
4 - 2 - 1 -> 2
5 - 

*/