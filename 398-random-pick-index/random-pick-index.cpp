class Solution {
public:
    unordered_map<int, vector<int>> M;
    Solution(vector<int>& nums) {
        int i=0;
        for(const auto& num: nums) {
            M[num].push_back(i++);
        }
    }
    
    int pick(int target) {
        int random = rand() % M[target].size();
        return M[target][random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */