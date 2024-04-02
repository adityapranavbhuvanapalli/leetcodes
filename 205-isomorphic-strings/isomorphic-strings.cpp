class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> fs(256, -1), ft(256, -1);
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(fs[s[i]] != -1 && fs[s[i]] != t[i])
                return false;

            if(ft[t[i]] != -1 && ft[t[i]] != s[i])
                return false;

            fs[s[i]] = t[i];
            ft[t[i]] = s[i];
        }

        return true;
    }
};