class Solution {
public:
    vector<int> prefix;
    int n, limit;
    Solution(vector<int>& w) {
        int sum = 0;
        prefix.resize(w.size());
        n = w.size();
        for(int i=0; i<n; i++) {
            sum += w[i];
            prefix[i] = sum;
        }

        limit = sum;
    }

    int pickIndex() {
        int random = rand() % limit;
        for(int i=0; i<n; i++) {
            if(prefix[i] > random)
                return i;
        }

        return n-1;
    }
};

/*

0   1   2   3   4   5

1   2   3
1   3   6

*/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */