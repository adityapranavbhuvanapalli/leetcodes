class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        string sign = (num >= 0) ? "" : "-";
        num = abs(num);

        if(num == 0)
            return "0";

        while(num) {
            res = to_string(num % 7) + res;
            num /= 7;
        }

        return sign + res;
    }
};