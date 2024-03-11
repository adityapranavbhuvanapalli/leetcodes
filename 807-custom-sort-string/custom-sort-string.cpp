class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> priority(26, 0);

        int x = 0;
        for(const auto& ch: order) {
            priority[ch - 'a'] = ++x;
        }    

        sort(s.begin(), s.end(), [&priority](auto& l, auto& r) {
            return priority[l - 'a'] < priority[r - 'a'];
        });

        return s;
    }
};

/*
cba
abcd
*/