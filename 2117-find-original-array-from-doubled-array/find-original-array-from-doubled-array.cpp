class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> res;
        unordered_map<int, int> freq;
        sort(changed.begin(), changed.end());

        for(const auto& ch: changed)
            freq[ch]++;

        for(const auto& ch: changed) {
            if(freq[ch] == 0)
                continue;

            freq[ch]--;

            if(freq[ch * 2] == 0)
                return {};

            freq[ch * 2]--;
            res.push_back(ch);
        }

        return res;
    }
};

/*
1   3   4   2   6   8
1   2   3   4   6   8

1   2   3   2   4   6
1   2   2   3   4   6

6   3   0   1
0   1   3   6

1 - 0
2 - 0
3 - 1
4 - 0
6 - 1
res: 1

n/2
1 - 1
2 - 0
3 - 1
4 - 1
6 - 0
8 - 1 

*/