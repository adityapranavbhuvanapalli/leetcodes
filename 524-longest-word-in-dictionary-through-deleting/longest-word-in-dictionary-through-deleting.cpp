class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";

        for(auto& word: dictionary) {
            if(!isSubsequence(word, s))
                continue;

            if(res.size() < word.size()) {
                res = word;
                continue;
            }

            if(res.size() == word.size() && word < res) {
                res = word;
                continue;
            }
        }

        return res;
    }

    bool isSubsequence(string& word, string& s) {
        int i = 0, n = word.size();

        for(const auto& ch: s) {
            if(word[i] == ch)
                i++;
            
            if(i == n)
                return true;
        }

        return false;
    }
};

/*
abpcplea
ale
apple
monkey
*/