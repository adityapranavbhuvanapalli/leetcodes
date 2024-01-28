class Solution {
public:
    string fractionToDecimal(int num, int den) {
        int sign = 1;

        if(num == 0)
            return "0";

        if((num > 0 && den < 0) || (num < 0 && den > 0))
            sign = -1;

        long numerator = abs((long)num);
        long denominator = abs((long)den);
        
        long x = numerator / denominator;
        long remainder = (numerator % denominator) * 10;
        unordered_map<int, int> dp;
        string res = to_string(x), decimal = "";
        int decimalSize = 0;

        while(remainder > 0) {
            if(dp.count(remainder)) {
                decimal.insert(decimal.begin() + dp[remainder], '(');
                decimal += ')';
                break;
            }
            decimal += to_string(remainder / denominator);
            dp[remainder] = decimalSize;
            decimalSize++;
            remainder = (remainder % denominator) * 10;
        }

        if(decimal != "")
            res += "." + decimal;

        if(sign < 0)
            res = "-" + res;
        return res;
    }
};

/*
3)4(1.3
  3
-----
  10
   9
-----
   10
*/