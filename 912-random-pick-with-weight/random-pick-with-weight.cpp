class Solution {
public:
    int n, limit = 0;
    vector<int> prefix;
    Solution(vector<int>& w) {
        n = w.size();
        for(const auto& e: w) {
            limit += e;
            prefix.push_back(limit);
        }
    }
    
    int pickIndex() {
        int randIdx = rand() % limit;

        int l = 0, r = n - 1, mid;

        while(l < r) {
            mid = l + (r - l) / 2;

            if(prefix[mid] > randIdx) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

/*
0   1   1   1

1   3
1 234
0   1
*/


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */