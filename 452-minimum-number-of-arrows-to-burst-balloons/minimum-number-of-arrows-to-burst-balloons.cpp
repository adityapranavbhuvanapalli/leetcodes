class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1, r;
        sort(points.begin(), points.end());

        r = points[0][1];
        for(const auto& point: points) {
            if(point[0] <= r) {
                r = min(r, point[1]);
            } else {
                r = point[1];
                count++;
            }
        }

        return count;
    }
};

/*
  -
  ---------   ---
 ----   ---------  
----


4


*/