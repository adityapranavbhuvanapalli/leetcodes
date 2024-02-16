class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int l = 0, collisions = 0;
        double curAngle = 0;
        vector<double> angles;

        for(auto& point: points) {
            if(location[0] == point[0] && location[1] == point[1]) {
                collisions++;
                continue;
            }

            angles.push_back(findAngle(location, point)); 
        }

        int n = angles.size();
        for(int i=0; i<n; i++) {
            angles.push_back(360 + angles[i]);
        }

        return collisions + findMaxPerception(angles, angle);
    }

    int findMaxPerception(vector<double>& angles, int angle) {
        int l = 0, n = angles.size(), maxVal = 0;
        sort(angles.begin(), angles.end());
        for(int r=0; r<n; r++) {
            while(l < r && angles[r] - angles[l] > angle)
                l++;

            maxVal = max(maxVal, r - l + 1);
        }

        return maxVal;
    }

    double findAngle(vector<int>& location, vector<int>& point) {
        double x1 = location[0], y1 = location[1];
        double x2 = point[0], y2 = point[1];

        return atan2(y2 - y1, x2 - x1) * 180 / M_PI;
    }
};

/*
            .
.
--------------

tan(0) = m = (y2-y1)/(x2-x1);

NOTE:
If atan(slope) is used, it is giving wrong answer
using atan2(y2-y1, x2-x1)
*/