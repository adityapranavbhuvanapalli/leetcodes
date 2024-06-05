class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size(), occ;
        vector<string> res;

        for(char ch='a'; ch<='z'; ch++) {
            occ = INT_MAX;

            for(auto& word: words) 
                occ = min(occ, findOccurences(word, ch));
            
            while(occ--)
                res.push_back(string(1, ch));
        }

        return res;
    }
    
    int findOccurences(string& s, char key) {
        int count = 0;

        for(const auto& ch: s)
            count += (ch == key);

        return count;
    }
};