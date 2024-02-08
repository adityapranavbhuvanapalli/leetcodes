class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> M;
        stack<int> s;
        vector<int> res;

        for(int i = n-1; i>=0; i--) {
            while(s.size() && s.top() < nums2[i])
                s.pop();

            M[nums2[i]] = s.size() ? s.top() : -1;

            s.push(nums2[i]);
        }

        for(const auto& num: nums1)
            res.push_back(M[num]);

        return res;
    }
};

/*
1   3   4   2
3   4  -1  -1

4   3
*/