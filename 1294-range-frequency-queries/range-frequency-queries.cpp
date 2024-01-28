class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> dp;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++) {
            dp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int l, r, n = dp[value].size(), mid;

        if(n == 0)
            return 0;

        l = 0, r = n - 1;
        while(l < r) {
            mid = l + (r - l) / 2;

            if(dp[value][mid] >= left)
                r = mid;
            else
                l = mid + 1;
        }

        int leftIdx = l;

        if(left > dp[value][leftIdx])
            return 0;

        l = 0, r = n - 1;
        while(l < r) {
            mid = l + ceil((r - l) / 2.0);

            if(dp[value][mid] <= right)
                l = mid;
            else
                r = mid - 1;
        }

        int rightIdx = r;
        
        if(right < dp[value][rightIdx])
            return 0;

        return rightIdx - leftIdx + 1;
    }
};

/*
11, 17
0   3   4   5   6   8   10
                        i
leftIdx - First Positive Version (A[mid] >= left)
rightIdx - Last Positive Version (A[mid] <= right)

*/
/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */