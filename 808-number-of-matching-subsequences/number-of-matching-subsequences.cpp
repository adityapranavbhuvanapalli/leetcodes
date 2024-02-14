class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size(), idx, count = words.size(), i;
        unordered_map<char, vector<int>> positions;

        for(int i=0; i<n; i++)
            positions[s[i]].push_back(i);

        for(auto& word: words) {
            idx = -1;
            i = 0;
            for(const auto& ch: word) {
                idx = binarySearch(positions[ch], idx + 1);
                if(idx == -1) {
                    // Not a subsequence
                    count--;
                    break;
                }
            }
        }

        return count;
    }

    int binarySearch(vector<int>& nums, int key) {
        // Finds a value in nums greater than or equal to the key
        int n = nums.size();
        if(n == 0 || key > nums.back())
            return -1;

        // Need to find the first occuring number which is >= key
        int l = 0, r = n - 1, mid;
        while(l < r) {
            mid = l + (r - l) / 2;

            if(nums[mid] >= key) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return nums[l];
    }
};

/*
d - 0
s - 1
a - 2   7
h - 3
j - 4   6
p - 5
u - 8 
f - 9
*/