class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n1; i++)
            pq.push({nums1[i] + nums2[0], 0});

        while (k-- && pq.size()) {
            auto [sum, j] = pq.top();
            pq.pop();

            res.push_back({sum - nums2[j], nums2[j]});

            if (j + 1 < n2)
                pq.push({sum - nums2[j] + nums2[j + 1], j + 1});
        }

        return res;
    }
};