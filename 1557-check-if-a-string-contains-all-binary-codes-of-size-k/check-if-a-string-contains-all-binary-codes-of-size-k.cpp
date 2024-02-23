class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        
        if (n <= k) 
            return false;

        unordered_set<string> uniq;
        for(int i=0; i<n - k + 1; i++)
            uniq.insert(s.substr(i, k));

        if(uniq.size() == pow(2, k))
            return true;

        return false;
    }
};

/*

*/