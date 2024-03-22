class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, maxLen = 0, count = 0;
        unordered_map<int, int> freq;
        for(int r=0; r<n; r++) {
            freq[fruits[r]]++;

            while(freq.size() > 2) {
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0)
                    freq.erase(fruits[l]);
                l++;
            }

            // cout<<l<<" "<<r<<endl;

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

/*
1   2   3   2   2
    l
        r

3   3   3   1   2   1   1   2   3   3   4
l
            r
*/