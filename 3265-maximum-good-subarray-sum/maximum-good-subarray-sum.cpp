class Solution {
public:
    const long long LONGMIN = -1000000000000000;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size();
        long long maxVal = LONGMIN, sum;
        unordered_map<long long, vector<int>> positions;
        vector<long long> prefix(n, 0);
        
        prefix[0] = nums[0];
        positions[nums[0]].push_back(0);
        for(int i=1; i<n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }
        
        for(int i=0; i<n; i++) {
            for(const auto& pos: positions[nums[i] + k]) {
                if(i > pos) {
                    sum = (pos == 0) ? prefix[i] : (prefix[i] - prefix[pos - 1]);
                }
                maxVal = max(maxVal, sum);
            }
            
            for(const auto& pos: positions[nums[i] - k]) {
                if(i > pos) {
                    sum = (pos == 0) ? prefix[i] : (prefix[i] - prefix[pos - 1]);
                }
                maxVal = max(maxVal, sum);
            }

            positions[nums[i]].push_back(i);
        }
        
        return maxVal == LONGMIN ? 0 : maxVal;
    }
};

/*
1
1   2   3   4   5   6
*/