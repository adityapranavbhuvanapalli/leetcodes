class Solution {
public:
    vector<string> stack;
    int calculate(string s) {
        s = rectify(s);
        vector<string> postfix = convert(s);
        return evaluatePostfix(postfix);
    }

    string rectify(string& s) {
        string res = "";

        for(const auto& ch: s)
            if(ch != ' ')
                res += ch;

        return res;
    }

    int evaluatePostfix(vector<string>& postfix) {
        vector<int> stack;
        int n=postfix.size(), op1, op2;
        for(int i=0; i<n; i++) {
            if(isNumber(postfix[i]))
                stack.push_back(stoi(postfix[i]));
            else {
                op1 = stack[stack.size()-1];
                stack.pop_back();
                op2 = stack[stack.size()-1];
                stack.pop_back();
                
                if(postfix[i]=="+")
                    stack.push_back(op1+op2);
                else if(postfix[i]=="-")
                    stack.push_back(op2-op1);
                else if(postfix[i]=="*")
                    stack.push_back(op1*op2);
                else if(postfix[i]=="/")
                    stack.push_back(op2/op1);
            }
        }
        return stack[0];
    }
    
    bool isNumber(string s) {
        char* p;
        strtol(s.c_str(), &p, 10);
        return *p == 0;
    }

    vector<string> convert(string infix) {
        vector<string> postfix;
        string num, tmp;
        vector<char> s;
        int n = infix.size();
        char ch;

        for(int i=0; i<n; i++) {
            ch = infix[i];

            if(ch == ' ')
                continue;
            else if(isdigit(ch)) {
                num = "";
                while(i<n && isdigit(infix[i])) {
                    num += infix[i++];
                }
                i--;
                postfix.push_back(num);
            } else if(ch == '(')
                s.push_back(ch);
            else if(ch == ')') {
                while(s.back() != '(') {
                    tmp = "";
                    tmp += s.back();
                    postfix.push_back(tmp);
                    s.pop_back();
                }
                s.pop_back();
            } else {
                while (s.size() && priority(ch) <= priority(s.back())){
                    tmp = "";
                    tmp += s.back();
                    postfix.push_back(tmp);
                    s.pop_back();
                }
                s.push_back(ch);
            }
        }
        while(s.size()) {
            tmp = "";
            tmp += s.back();
            postfix.push_back(tmp);
            s.pop_back();
        }
        return postfix;
    }

    int priority (char alpha) {
        if(alpha == '+' || alpha =='-')
            return 1;
    
        if(alpha == '*' || alpha =='/')
            return 2;
    
        return 0;
    }

};