class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i=0; i<n1; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(k-- && pq.size()) {
            auto v = pq.top();
            pq.pop();

            res.push_back({nums1[v[1]], nums2[v[2]]});

            if(v[2] < n2-1)
                pq.push({nums1[v[1]] + nums2[v[2]+1], v[1], v[2]+1});
        }

        return res;
    }
};