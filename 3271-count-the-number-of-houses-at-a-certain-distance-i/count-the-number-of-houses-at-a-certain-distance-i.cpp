class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> res(n, 0);
        int dist, nx = min(x, y), ny = max(x, y);

        for(int i=2; i<=n; i++) {
            for(int j=i; j>=1; j--) {
                dist = min({i - j, abs(j - x) + abs(i - y) + 1, abs(j - y) + abs(i - x) + 1});

                if(dist > 0)
                    res[dist - 1] += 2;
            }
        }

        return res;
    }
};