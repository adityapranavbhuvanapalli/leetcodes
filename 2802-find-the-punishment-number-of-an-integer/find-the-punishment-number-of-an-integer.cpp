class Solution {
public:
    int spaces = -1;
    int punishmentNumber(int n) {
        int punishment = 0;
        for(int i=1; i<=n; i++) {
            if(check(i)) {
                punishment += (i * i);
            }
        }
        return punishment;
    }

    bool check(int i) {
        int sqr = i * i;
        string str = to_string(sqr);
        int n = str.size();
        return solve(0, i, n, str);
    }

    bool solve(int start, int num, int n, string& s) {
        if(start >= n)
            return num == 0;

        for(int i=1; start+i<=n; i++) {
            int part = stoi(s.substr(start, i));
            if(num < part)
                break;

            if(solve(start + i, num - part, n, s))
                return true;
        }

        return false;
    }
};

/*
10
1   2   3   4   5   6   7   8   9   10

1000000
0123456
1
9
10
36


123
456
 78
----
*/