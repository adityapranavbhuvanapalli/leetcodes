class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size(), maxVal = 0, count = 0;

        sort(properties.begin(), properties.end(), [&](auto& l, auto& r) {
            return l[0] == r[0] ? l[1] > r[1] : l[0] < r[0];
        });
        
        for(int i=n-1; i>=0; i--) {
            if(properties[i][1] < maxVal)
                count++;

            maxVal = max(maxVal, properties[i][1]);
        }

        return count;
    }
};

/*
0   3,6
1   5,4
2   5,5
3   6,3

Sort based on Attack so we have to consider only Defence 
Iterate from end and keep track of max value so far

If Attack is equal, we cant use the traditional sorted way
Sort 2nd parameter descending so the min value is screened first
*/