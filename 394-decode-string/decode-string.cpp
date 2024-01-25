class Solution {
public:
    string decodeString(string msg) {
        stack<string> s;
        string res = "", count = "", part = "", compound;

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

            // Popping [
            s.pop();

            count = "";
            while(s.size() && isdigit(s.top()[0])) {
                count = s.top() + count;
                s.pop();
            }

            compound = "";
            for(int i=0; i<stoi(count); i++) {
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