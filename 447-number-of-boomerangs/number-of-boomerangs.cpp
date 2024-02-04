class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int res = 0, n = points.size(), distance;
        unordered_map<int, unordered_map<int, int>> M;  //(i, (dist, count))

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j)
                    continue;

                int first = points[i][0] - points[j][0];
                int second = points[i][1] - points[j][1];
                distance = first * first + second * second;
                res += M[i][distance];
                M[i][distance]++;
            }
        }

        return 2 * res;
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

n -> n*(n-1)

1   2   3   4   5
res = 20


2 + 4 + 6 + 8
*/