class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int sz = 0;
        unordered_map<int, int> freq;
        vector<vector<int>> res;

        for(const auto& num: nums)
            freq[num]++;

        for(const auto& [k, v]: freq) {
            for(int i=0; i<v; i++) {
                if(i == sz) {
                    res.push_back({});
                    sz++;
                }

                res[i].push_back(k);
            }
        }

        return res;
    }
};