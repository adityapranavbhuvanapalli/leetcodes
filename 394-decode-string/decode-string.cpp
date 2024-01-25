class Solution {
public:
    string decodeString(string msg) {
        stack<string> s;
        int count = 0;
        string res = "", part = "", compound, num;
        for(const auto& ch: msg) {
            if(ch != ']') {
                s.push(string(1, ch));
                continue;
            } 

            part = "";
            while(s.size() && s.top() != "[") {
                part = s.top() + part;
                s.pop();
            }

            s.pop();
            
            num = "";
            while(s.size() && isdigit(s.top()[0])) {
                num = s.top() + num;
                s.pop();
            }

            count = stoi(num);

            compound = "";
            while(count--) {
                compound += part;
            }

            s.push(compound);
        }

        while(s.size()) {
            res = s.top() + res;
            s.pop();
        }

        return res;
    }
};


/*
aaa
bcbc

*/