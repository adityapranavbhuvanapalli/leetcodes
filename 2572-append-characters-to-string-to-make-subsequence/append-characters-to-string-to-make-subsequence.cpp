class Solution {
public:
    int appendCharacters(string s, string t) {
        int ns = s.size(), nt = t.size();
        int j = 0;

        for(int i=0; i<ns; i++) {
            if(j == nt)
                break;

            if(s[i] == t[j])
                j++;
        }    

        return nt - j;
    }
};