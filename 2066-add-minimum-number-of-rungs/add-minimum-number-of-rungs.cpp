class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size(), prev = 0, count = 0;

        for(int i=0; i<n; i++) {
            if(rungs[i] - prev <= dist) {
                prev = rungs[i];
                continue;
            }

            count += (rungs[i] - prev - 1) / dist;
            prev = rungs[i];
        }

        return count;
    }
};