class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxOcc = 0, dominant, n = nums.size();

        for(const auto& num: nums)
            freq[num]++;

        // Finding dominant
        for(const auto& [k, v]: freq) {
            if(v > maxOcc) {
                dominant = k;
                maxOcc = v;
            }
        }

        int freqL = 0, freqR = freq[dominant];

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