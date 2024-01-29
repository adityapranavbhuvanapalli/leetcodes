class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0, top = 1;
        unordered_set<int> values;
        while(n) {
            if(values.count(k - top) == 0) {
                sum += top;
                values.insert(top);
                n--;
            }

            top++;
        }

        return sum;
    }
};

/*

*/