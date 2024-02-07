class Solution {
public:
    string frequencySort(string s) {
        // Store the frequency of each character
        unordered_map<char, int> frequency;
        for(const auto& ch: s)
            frequency[ch]++;

        // Sorting map based on values
        sort(s.begin(), s.end(), [&](auto& l, auto& r) {
            return frequency[l] == frequency[r] ? l > r : frequency[l] > frequency[r];
        });
        
        return s;
    }
};