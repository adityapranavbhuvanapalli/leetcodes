class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0, len = 0, top;

        for(top = 1; top <= min(n, k/2); top++) {
            sum += top;
            len++;
        }

        top = k;
        while(len < n) {
            sum += top;
            top++;
            len++;
        }

        return sum;
    }
};

/*
k = 8
1   2   3   4   5   6   7
0   1   2   3   4   5   6

k = 7
1   2   3   4   5   6
0   1   2   3   4   5
*/