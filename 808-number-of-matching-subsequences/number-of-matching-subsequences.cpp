class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size(), idx, count = words.size();
        unordered_map<char, vector<int>> positions;

        for(int i=0; i<n; i++) {
            positions[s[i]].push_back(i);
        }

        for(const auto& word: words) {
            idx = -1;
            for(const auto& ch: word) {
                idx = binarySearch(positions[ch], idx + 1);
                if(idx == -1) {
                    count--;
                    break;
                }
            } 
        }

        return count;
    }

    int binarySearch(vector<int>& positions, int x) {
        int n = positions.size(), l = 0, r = n - 1, mid;

        if(n == 0 || positions.back() < x)
            return -1;

        while(l < r) {
            mid = l + (r-l)/2;

            if(positions[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return positions[l];
    }
};

/*
abcde
a
bb
acd
ace

abdcdce
0 23
acd
032

Using binary search


0   3   4   6   11   20
*/