class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        vector<int> haystack(n - 1, 0);
        
        for(int i=0; i<n-1; i++) {
            if(nums[i] < nums[i+1])
                haystack[i] = 1;
            else if(nums[i] > nums[i+1])
                haystack[i] = -1;
            else
                haystack[i] = 0;
        }

        return kmp(haystack, pattern);
    }

    int kmp(vector<int>& haystack, vector<int>& pattern) {
        int n = haystack.size(), m = pattern.size();
        int i, j, prevlps, count = 0;
        vector<int> lps(m, 0);

        // Pre-Processing
        prevlps = 0, i = 1;
        while(i < m) {
            if(pattern[i] == pattern[prevlps]) {
                lps[i] = prevlps + 1;
                prevlps = lps[i];
                i++;
            } else {
                if(prevlps == 0) {
                    i++;
                } else {
                    prevlps = lps[prevlps - 1];
                }
            }
        }

        // Matching
        i = 0, j = 0;
        while(i < n) {
            if(haystack[i] == pattern[j]) {
                i++, j++;
            } else {
                if(j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
            if(j == m) {
                count++;
                j = lps[j - 1];
            }
        }

        return count;
    }
};