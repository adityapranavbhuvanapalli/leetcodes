class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        unordered_map<char, char> M = {{')', '('}, {'}', '{'}, {']', '['}, };
        for(auto& ch: s) {
            if(ch == '(' || ch == '{' || ch == '[')
                v.push(ch);
            else if(v.size() != 0 && M[ch] == v.top())
                v.pop();
            else
                return false;
        }
        
        return v.size() == 0;
    }
};