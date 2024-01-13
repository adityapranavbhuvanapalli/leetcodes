class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> remainders;

        for(auto& num: nums) {
            num = num % value;
            if(num < 0) {
                remainders[value + num]++;
            } else {
                remainders[num]++;
            }
        }

        int i=0;
        for(auto& [k, v]: remainders) {
            // cout<<k<<": "<<v<<endl;
            while(v--)
                nums[i++] = k + v * value;
        }

        // for(const auto& num: nums)
        //     cout<<num<<" ";

        // First missing non - negative
        i = 0;
        while (i < n) {
            while (i < n && nums[i] < n && nums[i] != i &&
                   nums[nums[i]] != nums[i]) {
                swap(nums[i], nums[nums[i]]);
            }
            i++;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i)
                return i;
        }

        return n;
    }
};