class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> M;
        vector<vector<string>> res;

        for(const auto& str: strs) {
            string t = str;
            sort(t.begin(), t.end());

            M[t].push_back(str);
        }

        for(const auto& [k, v]: M) {
            res.push_back(v);
        }

        return res;
    }
};

/*
eat, tea, ate
tan, nat
bat

aet, aet, aet

aet - ()
ant - ()
abt - ()
*/