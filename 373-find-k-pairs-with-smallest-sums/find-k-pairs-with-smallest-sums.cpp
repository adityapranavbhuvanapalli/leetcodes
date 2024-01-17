class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> res;

        auto compare = [&](auto& l, auto& r) {
            return (nums1[l[0]] + nums2[l[1]]) > (nums1[r[0]] + nums2[r[1]]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

        for(int i=0; i<n1; i++) {
            pq.push({i, 0});
        }

        while(k-- && pq.size()) {
            auto v = pq.top();
            pq.pop();

            res.push_back({nums1[v[0]], nums2[v[1]]});

            if(v[1] < n2-1)
                pq.push({v[0], v[1]+1});
        }

        return res;
    }
};