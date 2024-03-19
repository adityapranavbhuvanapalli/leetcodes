class Solution {
public:
    struct Compare {
        bool operator()(auto& l, auto& r) {
            return l.first - l.second > r.first - r.second;
        }
    };

    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int res = 0, n = reward1.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for(int i=0; i<n; i++) {
            pq.push({reward1[i], reward2[i]});
        }

        while(pq.size()) {
            if(pq.size() > k) {
                res += pq.top().second;
            } else {
                res += pq.top().first;
            }

            pq.pop();
        }

        return res;
    }
};

/*
1   1   3   4
4   4   1   1

14  14  31  41

*/