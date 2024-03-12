class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0, n = points.size(), distance;
        unordered_map<int, unordered_map<int, int>> M;  //(i, (dist, count))

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j)
                    continue;

                int first = points[i][0] - points[j][0];
                int second = points[i][1] - points[j][1];
                distance = first * first + second * second;
                // res += 2 * M[i][distance];
                M[i][distance]++;
            }
        }

        for(int i=0; i<n; i++) {
            for(const auto& [k, v]: M[i]) 
                res += v * (v - 1);
        }

        return res;
    }
};

/*
0,0     1,0     2,0

0,0
    1,0 - 1
    2,0 - 2

1,0
    1 - (0,0), (2,0)
    
2,0
    ..
*/