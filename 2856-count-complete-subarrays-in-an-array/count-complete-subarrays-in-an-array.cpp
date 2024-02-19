class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), count = 0, number = 0;
        unordered_set<int> uniq;

        for(int i=0; i<n; i++)
            uniq.insert(nums[i]);
        number = uniq.size();

        for(int i=0; i<n; i++) {
            unordered_set<int> u;
            for(int j=i; j<n; j++) {
                u.insert(nums[j]);
                if(u.size() == number) {
                    count += n - j;
                    break;
                }
            }
        }
        return count;
    }
};

/*

*/