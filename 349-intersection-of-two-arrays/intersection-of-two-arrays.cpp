class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s1, s2;
        
        for(const auto& num: nums1) 
            s1.insert(num);
        
        
        for(const auto& num: nums2) 
            s2.insert(num);
        
        for(const auto& num: s1) {
            if(s2.count(num) == 1)
                res.push_back(num);
        }
        
        return res;
    }
};