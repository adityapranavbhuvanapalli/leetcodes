class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> f;

        char y = 'a';
        for(const auto& x: order)
            f[x] = y++;

        for(auto& word: words)
            for(auto& x: word)
                x = f[x];

        vector<string> sorts(words);
        sort(sorts.begin(), sorts.end());

        return words == sorts;
    }
};