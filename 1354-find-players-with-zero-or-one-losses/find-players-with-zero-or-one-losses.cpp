class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> winners, secondwinners;
        map<int, pair<int, int>> M;
        for(auto match: matches) {
            M[match[0]].first++;
            M[match[0]].second++;
            M[match[1]].first++;
        }

        for(auto m: M) {
            if(m.second.first==m.second.second)
                winners.push_back(m.first);
            else if(m.second.first==m.second.second+1)
                secondwinners.push_back(m.first);
        }

        return {winners, secondwinners};
    }
};