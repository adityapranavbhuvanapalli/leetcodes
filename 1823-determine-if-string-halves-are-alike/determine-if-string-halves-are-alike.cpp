class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0, n = s.size();
        
        for(int i=0; i<n; i++) {
            if(isVowel(s[i])) {
                if(i < n/2)
                    count++;
                else
                    count--;
            }
        }

        return count == 0;
    }

    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};