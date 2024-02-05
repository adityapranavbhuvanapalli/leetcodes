class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0, n = points.size(), xChisato, yChisato, minY;
        sort(points.begin(), points.end(), [&](auto& l, auto& r) {
            return l[0] == r[0] ? l[1] > r[1] : l[0] < r[0];
        });
        
        for(int i=0; i<n; i++) {
            // cout<<"("<<points[i][0]<<", "<<points[i][1]<<"), ";
            minY = -1;
            xChisato = points[i][0];
            yChisato = points[i][1];
            for(int j=i+1; j<n; j++) {
                if(yChisato < points[j][1])
                    continue;
                
                if(points[j][1] <= minY)
                    continue;
                
                count++;
                minY = points[j][1];
            }
        }
        
        // cout<<endl;
        
        return count;
    }
};