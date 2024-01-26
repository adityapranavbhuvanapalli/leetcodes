class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 0, mid, sum;

        for(const auto& quantity: quantities)
            r = max(r, quantity);

        while(l < r) {
            mid = l + (r-l)/2;

            sum = 0;
            for(const auto& quantity: quantities) {
                sum += ceil(quantity / (double)mid);
            }

            if(sum <= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

/*
1. Identify l, r
    - l = 1
    - r = max. of quantities

2. Identify First Positive Version / Last Positive Version
    - First Positive Version

3. Pass Condition: sum <= n


1   11  - 6 -> 2 + 1 = 3 <= 6 
1   6   - 3 -> 4 + 2 = 6 <= 6
1   3   - 2 -> 6 + 3 = 9 > 6 
3   3
*/