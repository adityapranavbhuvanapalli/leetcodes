class Solution {
public:
    int res = 0;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int cur = 0, n = words.size();
        vector<int> freq(26, 0);
        vector<int> wordScore(n, 0);

        for(const auto& letter: letters) {
            freq[letter - 'a']++;
        }

        for(int i=0; i<n; i++) {
            wordScore[i] = 0;
            for(const auto& ch: words[i]) {
                wordScore[i] += score[ch - 'a'];
            }
        }

        backtrack(0, n, words, wordScore, freq, cur);
        return res;
    }

    void backtrack(int start, int n, vector<string>& words, vector<int>& wordScore, vector<int>& freq, int& cur) {
        res = max(res, cur);

        for(int i=start; i<n; i++) {
            if(!isPossible(words[i], freq))
                continue;

            // Remove word from freq
            for(const auto& ch: words[i])
                freq[ch - 'a']--;
            
            // Increase the score by wordScore[i]
            cur += wordScore[i];
            // Backtrack
            backtrack(i + 1, n, words, wordScore, freq, cur);
            // Decrease the score by wordScore[i]
            cur -= wordScore[i];

            // Add word from freq
            for(const auto& ch: words[i])
                freq[ch - 'a']++;
        }
    }

    bool isPossible(string& word, vector<int> freq) {
        for(const auto& ch: word) {
            if(freq[ch - 'a'] == 0)
                return false;

            freq[ch - 'a']--;
        }

        return true;
    }
};

/*
dog
cat
dad
good

a - 2
c - 1
d - 3
g - 1
o - 2
*/