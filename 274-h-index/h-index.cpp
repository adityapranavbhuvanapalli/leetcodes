class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = 0, mid;
        for(const auto& citation: citations)
            r = max(r, citation);

        sort(citations.begin(), citations.end());
    
        while(l < r) {
            mid = l + ceil((r-l) / 2.0);

            if(binary(citations, mid))
                l = mid;
            else
                r = mid - 1;
        }

        return r;
    }

    bool binary(vector<int>& citations, int k) {
        int l = 0, n = citations.size(), r = n - 1, mid;
        while(l < r) {
            mid = l + (r-l) / 2;

            if(citations[mid] < k)
                l = mid + 1;
            else
                r = mid;
        }

        return n - l >= k;
    }
};

/*
3   0   6   1   5
0   1   3   5   6


1   3   1
1   1   3

*/