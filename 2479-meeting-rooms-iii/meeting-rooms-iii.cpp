class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        long busiestRoom = INT_MAX, maxCount = 0;
        vector<int> rooms(n, 0);
        priority_queue<long, vector<long>, greater<long>> freeRooms;
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> occupied;

        for(int i=0; i<n; i++)
            freeRooms.push(i);
        
        sort(meetings.begin(), meetings.end());

        for(const auto& meeting: meetings) {
            while(occupied.size() && occupied.top().first <= meeting[0]) {
                freeRooms.push(occupied.top().second);
                occupied.pop();
            }

            long freeRoom, endTime;

            if(freeRooms.size()) {
                freeRoom = freeRooms.top();
                freeRooms.pop();
                endTime = meeting[1];
            } else {
                auto [delay, room] = occupied.top();
                freeRoom = room, endTime = delay - meeting[0] + meeting[1];
                occupied.pop();
            }

            occupied.push({endTime, freeRoom});

            rooms[freeRoom]++;
            if(maxCount < rooms[freeRoom]) {
                maxCount = rooms[freeRoom];
                busiestRoom = freeRoom;
            } else if(maxCount == rooms[freeRoom]) {
                busiestRoom = min(busiestRoom, freeRoom);
            }
        }

        return busiestRoom;
    }
};

/*
0   1   2
20  10  5

1,20    2,10    3,5     4,9     6,8
                        i

0   1
14  

0,10    1,2     12,14   13,15
                i
*/