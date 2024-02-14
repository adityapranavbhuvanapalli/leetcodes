class Solution {
public:
    bool canTransform(string start, string end) {
        int i1 = 0, i2 = 0, n = start.size();
        
        while(i1 < n && i2 < n) {
            while(start[i1] == 'X')
                i1++;
            while(end[i2] == 'X')
                i2++;

            if(i1 == n || i2 == n)
                break;

            if(start[i1] != end[i2])
                return false;

            // If start[i1] is L then, it can only move backward
            if(start[i1] == 'L' && i1 < i2)
                return false;

            // If cur char is R, then it can only move forward
            if(start[i1] == 'R' && i1 > i2)
                return false;

            i1++, i2++;
        }

        // Ignore all X at the end
        while(i1 < n && start[i1] == 'X')
            i1++;
        
        while(i2 < n && end[i2] == 'X')
            i2++;

        return i1 == n && i2 == n;
    }
};

/*
Observations:
1. If we ignore all X, then start and end should match
    R..LR.R.L
    .RL..RRL.

2. L can move backward only, R can move forward only
*/