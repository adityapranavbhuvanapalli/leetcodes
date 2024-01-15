class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, int> M;

        for (const auto& ch : s)
            M[ch]++;

        for (int i = 0; i < n; i++)
            if (M[s[i]] == 1)
                return i;

        return -1;
    }
};