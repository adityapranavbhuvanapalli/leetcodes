class MyCalendar {
public:
    vector<pair<int, int>> calendar;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(calendar.size() == 0 || calendar.back().second <= start) {
            calendar.push_back({start, end});
            return true;
        }

        int idx = binarySearch(start);

        auto& [x, y] = calendar[idx];

        if(start <= x && end <= x) {
            calendar.insert(calendar.begin() + idx, {start, end});
            return true;
        }

        return false;
    }

    int binarySearch(int val) {
        int l = 0, n = calendar.size(), r = n - 1, mid;

        while(l < r) {
            mid = l + (r - l) / 2;

            if(calendar[mid].second <= val) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};

/*
3,8     19,25   25,32   33,41   47,50   
*/
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */