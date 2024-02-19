class Solution {
public:
    int countSegments(string s) {
        int n = s.size(), spaces = 0;

        if(n == 0)
            return 0;

        for(int i=0; i<n; i++) {
            if(s[i] == ' ' && (i > 0 && s[i - 1] != ' '))
            spaces ++;
        }

        return spaces + (s[n - 1] != ' ');
    }
};