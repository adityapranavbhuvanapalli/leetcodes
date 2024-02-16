class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int res = INT_MAX;
        unordered_set<string> goals = findTime(targetSeconds);

        char src = '0' + startAt;

        for(auto goal: goals) {
            cout<<goal<<endl;
            res = min(res, solve(0, src, 0, moveCost, pushCost, goal));
        }

        return res;
    }

    int solve(int i, int src, int found, int move, int push, string& s) {
        if(i == s.size())
            return 0;

        if(!found && s[i] == '0')
            return solve(i + 1, src, found, move, push, s);

        found = true;
        if(src == s[i])
            return push + solve(i + 1, src, found, move, push, s);

        return move + solve(i, s[i], found, move, push, s); 
    }

    unordered_set<string> findTime(int target) {
        int minutes = target / 60;
        int seconds = target % 60;

        unordered_set<string> res;

        string minStr;
        string secStr;

        if(minutes < 100) {
            minStr = to_string(minutes);
            secStr = to_string(seconds);
            if(minStr.size() == 1)
                minStr = "0" + minStr;
            if(secStr.size() == 1)
                secStr = "0" + secStr;

            res.insert(minStr + secStr);
        }

        if(seconds >= 40 || minutes == 0)
            return res;

        minutes--, seconds += 60;
        minStr = to_string(minutes);
        secStr = to_string(seconds);
        if(minStr.size() == 1)
            minStr = "0" + minStr;
        if(secStr.size() == 1)
            secStr = "0" + secStr;
        
        res.insert(minStr + secStr);

        return res;
        
    }
};

/*
599
10:59
09:119 X
*/