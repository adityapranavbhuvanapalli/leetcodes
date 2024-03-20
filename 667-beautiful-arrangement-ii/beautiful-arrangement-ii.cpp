class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        
        for(int i=0; i<n; i++)
            res[i] = i + 1;

        while(k > 1) {
            reverse(res.begin(), res.begin() + k);
            k--;
        }

        return res;
    }
};

/*
1   2   3   4   111
1   2   4   3   121
1   3   2   4   212
1   3   4   2   212
1   4   2   3   321
1   4   3   2   311
*/