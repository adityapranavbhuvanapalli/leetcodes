class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int val = 0, count = 0;
        for (const auto& num : nums)
            val = val ^ num;

        val = val ^ k;
        
        while (val) {
            count += (val & 1);
            val = (val >> 1);
        }

        return count;
    }
};

/*
111010100
111010011
---------
111010000
111001111
---------
111000000
*/