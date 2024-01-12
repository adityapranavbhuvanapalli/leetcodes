class Solution {
public:
    bool halvesAreAlike(string s) {
        char ch;
        int count = 0, l = 0, r = s.size() - 1;
        
        while(l < r) {
            ch = tolower(s[l]);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                count++;

            ch = tolower(s[r]);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                count--;

            l++, r--;
        }

        return count == 0;
    }
};