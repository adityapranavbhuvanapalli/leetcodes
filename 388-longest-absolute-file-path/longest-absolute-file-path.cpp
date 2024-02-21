class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> s;
        string cur = "";
        int curTabCount = 0, curLength = 0, maxVal = 0;
        bool file = false;

        input += "\n";

        for(const auto& ch: input) {
            if(ch == '\t') {
                curTabCount++;
                continue;
            }

            if(ch == '\n') {
                while(curTabCount < s.size()) {
                    curLength -= s.top().size();
                    s.pop();
                }

                curLength += cur.size();
                s.push(cur);

                if(file) {
                    maxVal = max(maxVal, curLength + (int)s.size() - 1);
                    file = false;
                }

                cur = "";
                curTabCount = 0;
                continue;
            }

            if(ch == '.') {
                file = true;
            }

            cur += ch;
        }

        return maxVal;
    }
};

/*
maxVal = 18
curLength = 10
curTabCount = 2
tabs = 1

cur = subsubdir1

dir 
subdir1

*/