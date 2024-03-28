class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), arrows = 1;
        
        sort(points.begin(), points.end());
    
        int r = points[0][1];
        for(const auto& point: points) {
            if(point[0] <= r) {
                r = min(r, point[1]);
            } else {
                r = point[1];
                arrows++;
            }
        }

        return arrows;
    }
};

/*
   -
  -
  ---------   ---
 ----   ---------  
----


4
   --
  --
 --
--

*/