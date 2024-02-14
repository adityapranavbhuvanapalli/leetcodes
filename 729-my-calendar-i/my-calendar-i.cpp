class MyCalendar {
public:
    vector<vector<int>> calendar;
    MyCalendar() {
        // calendar = {{10, 20}, {20, 30}, {40, 50}};
        // cout<<binarySearch(5,15)<<endl;
        // cout<<binarySearch(5,10)<<endl;
        // cout<<binarySearch(25,40)<<endl;
        // cout<<binarySearch(25,45)<<endl;
        // cout<<binarySearch(30,45)<<endl;
    }
    
    bool book(int start, int end) {
        if(calendar.size() == 0) {
            calendar.push_back({start, end});
            return true;
        }

        int n = calendar.size(), idx = binarySearch(start, end);

        // TODO: Should handle the case for last (idx will be n-1 but should be at n)
        if(idx == n-1) {
            if(calendar[idx][1] <= start) {
                calendar.push_back({start, end});
                return true;
            }
        }

        if(end > calendar[idx][0])
            return false;

        calendar.insert(calendar.begin() + idx, {start, end});
        return true;
    }

    int binarySearch(int start, int end) {
        int n = calendar.size(), l = 0, r = n - 1, mid;
        while(l < r) {
            mid = l + (r - l) / 2;
        
            if(calendar[mid][1] <= start) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};
/*
10 - 20
40 - 50
15 - 25
20 - 30

10,20   20,30   40,50

5,15
5,10
25,40
25,45
30,45

Find first interval that is greater than start
*/

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */