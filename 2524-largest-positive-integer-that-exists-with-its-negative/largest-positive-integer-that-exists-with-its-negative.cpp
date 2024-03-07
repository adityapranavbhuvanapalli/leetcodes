class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;

        unordered_set<int> uniq;
        for(const auto& num: nums) {
            if(uniq.count(-num) == 1 && res < abs(num)) {
                res = abs(num);
            }

            uniq.insert(num);
        }

        return res;
    }
};

/*

*/