class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        vector<int> M(26, 0);

        for(auto& c: s) {
            count++;
            M[c - 'a']++;
        }

        for(auto& c: t) {
            if(M[c - 'a'] > 0)
                count--;
            else 
                count++;
            M[c - 'a']--;
        }

        // for(auto& [k, v]: M)
        //     count += abs(v);

        return count;
    }
};