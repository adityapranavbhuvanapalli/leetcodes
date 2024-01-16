class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer(2);
        map<int, int> losses; 

        for(const auto& match: matches) {
            if(losses.count(match[0]) == 0)
                losses[match[0]] = 0;
            losses[match[1]]++;
        }

        for(const auto& [k, v]: losses)
            if(v == 0 || v == 1)
                answer[v].push_back(k);

        return answer;
    }
};