class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0, n = s.size();
        char ch;
        
        for(int i=0; i<n; i++) {
            ch = tolower(s[i]);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                if(i < n/2)
                    count++;
                else
                    count--;
            }
        }

        return count == 0;
    }
};