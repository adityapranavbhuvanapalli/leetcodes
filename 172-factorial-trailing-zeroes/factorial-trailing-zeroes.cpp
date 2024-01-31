class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;

        for(int i=1; i<=n; i++) {
            if(i % 3125 == 0)
                count += 5;
            else if(i % 625 == 0)
                count += 4;
            else if(i % 125 == 0)
                count += 3;
            else if(i % 25 == 0)
                count += 2;
            else if(i % 5 == 0)
                count++;
        }

        return count;
    }
};

/*
5 - 1
10 - 0
29 28 27 26 24 23 21 19 18 17 16 14 13 11 9 8 7 6 4 3 1

30, (25,24), 20, (15,12), 10, (5,2)
*/