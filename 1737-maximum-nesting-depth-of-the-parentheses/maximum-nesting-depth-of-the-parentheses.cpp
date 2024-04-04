class Solution {
public:
    int maxDepth(string s) {
        int open = 0, maxDepth = 0;

        for(const auto& ch: s) {
            if(ch == '(') {
                open++;
            } else if(ch == ')') {
                maxDepth = max(maxDepth, open);
                open--;
            }
        }

        return maxDepth;
    }
};

/*
AB
*/