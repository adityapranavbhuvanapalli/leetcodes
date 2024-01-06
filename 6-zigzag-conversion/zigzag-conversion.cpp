class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        int n = s.size();

        if(numRows == 1)
            return s;

        for(int k=0; k<numRows; k++) {
            for(int i=k; i<n; i+= (2* numRows - 2)) {
                res += s[i];
                if(k == 0 || k == numRows - 1)
                    continue;
                if(i+2*(numRows - k - 1) < n)
                    res += s[i+2*(numRows - k - 1)];
            }
        }

        return res;
    }
};