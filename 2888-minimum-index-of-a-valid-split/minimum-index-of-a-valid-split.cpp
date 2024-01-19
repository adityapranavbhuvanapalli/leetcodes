class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int occ = 0, dominant = nums[0], n = nums.size(), freqL = 0, freqR = 0;

        // Finding dominant
        for(const auto& num: nums) {
            if(num == dominant)
                occ++;
            else 
                occ--;
            
            if(occ < 0) {
                dominant = num;
                occ = 1;
            }
        }

        for(const auto& num: nums) {
            if(dominant == num)
                freqR++;
        }

        // Find split based on frequencies of dominant
        for(int i=0; i<n; i++) {
            if(nums[i] == dominant) {
                freqL++;
                freqR--;
            }

            if(freqL * 2 > (i + 1) && freqR * 2 > (n - i - 1))
                return i;
        }

        return -1;
    }
};

/*
2   1   3   1   1   1   7   1   2   1
// Find dominant
// Find split based on freq of dominant
// i+1 will be length of left array at index i, n - i - 1 will be length of right array from i 
*/