class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0, cows = 0;
        unordered_map<char, int> found;
        unordered_set<int> bullSet;

        for(const auto& ch: secret)
            found[ch]++;

        for(int i=0; i<n; i++) {
            if(secret[i] == guess[i]) {
                bulls++;
                bullSet.insert(i);
                found[guess[i]]--;
            }
        }
        
        for(int i=0; i<n; i++) {
            if(bullSet.count(i) == 0 && found[guess[i]] > 0) {
                found[guess[i]]--;
                cows++;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

/*
1   8   0   7
7   8   1   0

1   1   2   3
0   1   1   1
*/