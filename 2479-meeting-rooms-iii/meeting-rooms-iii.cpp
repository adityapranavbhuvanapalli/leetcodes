class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        long busiest = 0, maxCount = 0;
        vector<long> count(n, 0);
        priority_queue<long, vector<long>, greater<long>> free;
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> busy;

        for(int i=0; i<n; i++)
            free.push(i);

        sort(meetings.begin(), meetings.end());

        for(const auto& meeting: meetings) {
            while(busy.size() && busy.top().first <= meeting[0]) {
                free.push(busy.top().second);
                busy.pop();
            }

            if(free.size()) {
                int room = free.top();
                free.pop();
                count[room]++;
                busy.push({meeting[1], room});
                continue;
            }

            auto [endTime, room] = busy.top();
            busy.pop();

            count[room]++;
            busy.push({meeting[1] + endTime - meeting[0], room});
        }

        for(int i=0; i<n; i++) {
            if(maxCount < count[i]) {
                maxCount = count[i];
                busiest = i;
            }
        }

        return busiest;
    }
};

/*
    0   1   2
c:  0   0   0

e:  10  5  12 

1,20    2,10     3,5     4,9    6,8
*/