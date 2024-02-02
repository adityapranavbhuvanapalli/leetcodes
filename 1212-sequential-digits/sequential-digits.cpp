class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int val, adder = 1;
        vector<int> res;
        for(int i=2; i<10; i++) {
            // Form start val
            val = 1;
            for(int j=1; j<i; j++) 
                val = val*10 + (j+1);

            if(val > high)
                return res;
            if(val >= low)
                res.push_back(val);

            // Increment by 11..11
            adder = adder * 10 + 1;
            for(int j=0; j<9-i; j++) {
                val += adder;

                if(val > high)
                    return res;
                if(val >= low)
                    res.push_back(val);
            }
        }    

        return res;
    }
};

/*
100 - 10000

x = y = 1
y = y*10 + (x+1)
x++;

1*10+1 = 11
11*10 + 1 = 111
111*10 + 1 = 1111
                                            n
12, 23, 34, 45, 56, 67, 78, 89          - 8(2)
123, 234, 345, 456, 567, 678, 789       - 7(3)
1234, 2345, 3456, 4567, 5678, 6789      - 6(4)
                                        - 5(5)
                                        - 4(6)
                                        - 3(7)
                                        - 2(8)
*/