class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, l = 0, r = tokens.size() - 1, maxVal = 0;
        sort(tokens.begin(), tokens.end());

        while(l <= r) {
            if(power >= tokens[l]) {
                power -= tokens[l++];
                score++;
                maxVal = max(maxVal, score);
            } else if(score > 0) {
                score--;
                power += tokens[r--];
            } else {
                break;
            }
        }

        return maxVal;
    }
};

/*
50

0
*/