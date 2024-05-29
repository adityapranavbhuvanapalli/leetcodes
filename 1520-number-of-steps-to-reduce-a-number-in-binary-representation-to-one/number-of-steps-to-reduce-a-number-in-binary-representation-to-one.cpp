class Solution {
public:
    int numSteps(string s) {
        int count = 0;

        while(s.size() > 1) {
            if(s.back() == '0') {
                s.pop_back();
            } else {
                int first = s.size() - 1;
                while(first >= 0) {
                    if(s[first] == '0')
                        break;
                    first--;
                }
                for(int i=s.size() - 1; i>first; i--)
                    s[i] = '0';

                if(first == -1) 
                    s = "1" + s;
                else 
                    s[first] = '1';
            }
            count++;
        }

        return count;
    }
};

/*
111111
*/