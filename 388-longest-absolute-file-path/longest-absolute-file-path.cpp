class Solution {
public:
    int lengthLongestPath(string input) {
        int maxLen = 0, len = 0;
        bool isFile = false;
        int tabs = 0;
        stack<string> s;
        string str = "";

        input += "\n";

        cout<<input<<endl<<endl;

        for(const auto& ch: input) {
            if(ch == '\t') {
                tabs++;
                continue;
            }

            if(ch == '\n') {
                cout<<str<<"("<<tabs<<"): "<<endl;
                while(tabs < s.size()) {
                    len -= s.top().size();
                    s.pop();
                }

                s.push(str);
                len += str.size();
                stack<string> tmp(s);
                while(tmp.size()) {
                    cout<<tmp.top()<<"<-";
                    tmp.pop();
                }
                cout<<endl;

                str = "";
                tabs = 0;
                // MARK: If str is a file name, then update maxLen
                if(isFile) {
                    maxLen = max(maxLen, len + (int)s.size() - 1);
                    isFile = false;
                }
                
                continue;
            }

            // cout<<ch<<": "<<endl;
            str += ch;
            if(ch == '.')
                isFile = true;

        }

        return maxLen;
    }
};