class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN, area = 0;
        bool corners = true;
        set<pair<int, int>> points;
        
        for(const auto& r: rectangles) {
            x1 = min(x1, (long)r[0]);
            x2 = max(x2, (long)r[2]);
            
            y1 = min(y1, (long)r[1]);
            y2 = max(y2, (long)r[3]);

            area += abs(r[3] - r[1]) * (long)abs(r[2] - r[0]);
            
            if(!points.insert({r[0], r[1]}).second)
                points.erase({r[0], r[1]});
            if(!points.insert({r[0], r[3]}).second)
                points.erase({r[0], r[3]});
            if(!points.insert({r[2], r[3]}).second)
                points.erase({r[2], r[3]});
            if(!points.insert({r[2], r[1]}).second)
                points.erase({r[2], r[1]});
        }
        
        if(!points.count({x1, y1}) || !points.count({x1, y2}) || !points.count({x2, y1}) || !points.count({x2, y2}) || points.size() != 4)
            return false;

        return area == (x2 - x1) * (y2 - y1); 
    }
};

/*
(x1,y2)(x2,y2)
(x1,y1)(x2,y1)
*/