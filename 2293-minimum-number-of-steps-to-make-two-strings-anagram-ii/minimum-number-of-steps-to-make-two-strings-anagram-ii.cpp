class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        int M[26] = {0};

        for(const auto& c: s)
            M[c - 'a']++;

        for(const auto& c: t)
            M[c - 'a']--;

        for(int i=0; i<26; i++)
            count += abs(M[i]);

        return count;
    }
};