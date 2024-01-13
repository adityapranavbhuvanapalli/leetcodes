class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        unordered_map<char, int> freq;

        for (const auto& ch : s)
            freq[ch]++;

        for (const auto& ch : t)
            freq[ch]--;

        for (const auto& [k, v] : freq)
            if(v > 0)
                res += v;

        return res;
    }
};