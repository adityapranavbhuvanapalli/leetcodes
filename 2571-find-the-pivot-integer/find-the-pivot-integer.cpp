class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0, total = n * (n + 1) / 2;

        for(int i=1; i<=n; i++) {
            sum += i;

            if(sum == total)
                return i;

            total -= i;
        }

        return -1;
    }
};