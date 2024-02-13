class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size(), res = INT_MAX;
        vector<int> minutes(n, 0);

        for(int i=0; i<n; i++) {
            auto& point = timePoints[i];
            minutes[i] = stoi(point.substr(0, 2)) * 60 + stoi(point.substr(3));
        }

        sort(minutes.begin(), minutes.end());

        for(int i=0; i<n; i++) {
            // cout<<minutes[i]<<" ";
            int a = minutes[i];
            int b = minutes[(i + 1) % n];

            res = min({res, abs(b - a), abs(1440 + b - a)});
        }

        return res;
    }
};

/*
0....1439
24*60=1440
*/