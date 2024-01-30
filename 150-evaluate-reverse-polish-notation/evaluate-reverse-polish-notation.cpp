class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int op1, op2;
        for(auto& token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                op1 = s.top(), s.pop();
                op2 = s.top(), s.pop();
                if(token == "+")
                    s.push(op1 + op2);
                else if(token == "-")
                    s.push(op2 - op1);
                else if(token == "*")
                    s.push(op1 * op2);
                else if(token == "/")
                    s.push(op2 / op1);
            } else {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};