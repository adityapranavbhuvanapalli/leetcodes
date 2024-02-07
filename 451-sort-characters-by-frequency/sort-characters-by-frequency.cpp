class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frequency;
        for(const auto& ch: s)
            frequency[ch]++;

        sort(s.begin(), s.end(), [&](auto& l, auto& r) {
            return frequency[l] == frequency[r] ? l > r : frequency[l] > frequency[r];
        });
        
        return s;
    }
};