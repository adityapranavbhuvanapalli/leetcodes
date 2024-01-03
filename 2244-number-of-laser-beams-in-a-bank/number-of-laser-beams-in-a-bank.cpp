class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int a = 0, b = 0, res = 0;

        for (const auto& row : bank) {
            if (b != 0)
                a = b;

            b = 0;
            for (const auto& ch : row)
                if (ch == '1')
                    b++;

            res += (a * b);
        }

        return res;
    }
};