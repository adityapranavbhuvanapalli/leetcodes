class Solution {
public:
    int lengthLongestPath(string input) {
        int maxLen = 0, len = 0;
        bool isFile = false;
        int tabs = 0;
        stack<string> s;
        string str = "";

        input += "\n";

        for(const auto& ch: input) {
            if(ch == '\t') {
                tabs++;
                continue;
            }

            if(ch == '\n') {
                while(tabs < s.size()) {
                    len -= s.top().size();
                    s.pop();
                }

                s.push(str);
                len += str.size();
                str = "";
                tabs = 0;
                
                if(isFile) {
                    maxLen = max(maxLen, len + (int)s.size() - 1);
                    isFile = false;
                }
                
                continue;
            }

            str += ch;
            if(ch == '.')
                isFile = true;
        }

        return maxLen;
    }
};