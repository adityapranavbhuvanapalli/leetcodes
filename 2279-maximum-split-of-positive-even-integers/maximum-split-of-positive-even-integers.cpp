class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        // If number is odd
        if(finalSum & 1)
            return {};
            
        long long currSum = 0, i = 2;
        vector<long long> res;

        // Pick greedily (smallest element possible)
        while(currSum + i <= finalSum) {
            res.push_back(i);
            currSum += i;
            i += 2;
        }

        if(finalSum > currSum) {
            if(finalSum - currSum > i)
                res.push_back(finalSum - currSum);
            else
                res.back() += finalSum - currSum;
        }

        return res;
    }
};

/*
28

28

2   4   6   
*/