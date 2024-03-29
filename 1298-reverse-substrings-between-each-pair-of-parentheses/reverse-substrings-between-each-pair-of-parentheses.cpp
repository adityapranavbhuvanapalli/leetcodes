class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        string res = "";
        
        for(const auto& ch: s) {
            if(ch != ')') {
                stk.push(ch);
                continue;
            } 
            
            string part = "";
            while(stk.top() != '(') {
                part += stk.top();
                stk.pop();
            }
            
            // Popping (
            stk.pop();
            
            for(const auto& c: part)
                stk.push(c);
        }

        while(stk.size()) {
            res = stk.top() + res;
            stk.pop();
        }

        return res;
    }
};