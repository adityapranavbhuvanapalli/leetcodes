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
        int l = 0, r = n-1, mid;
        while(l < r) {
            mid = l + (r - l) / 2;

            if(random < prefix[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};

/*

1   2   3   4   5

1   2   1   2   3
1   3   4   6   9     / 9
0   1   2   3   4


5, 6
3, 3
*/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */