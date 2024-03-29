class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int i = 0, n = events.size(), res = 0;
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int d=1; d<=1e5; d++) {
            while(pq.size() && pq.top() < d)
                pq.pop();
            
            while(i < n && events[i][0] == d) {
                pq.push(events[i][1]);
                i++;
            }
            
            if(pq.size()) {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};

/*
0-  1
1-  1   2   3
2-          3   4
3-              4
4-              4
------------------
d=0

1,1
1,3
3,4
4,4
4,4

*/