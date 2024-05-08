class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> res(n), ref = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<n; i++) {
            pq.push({score[i], i});
        }

        int i = 0;
        while(pq.size()) {
            auto& [val, idx] = pq.top();
            res[idx] = i < ref.size() ? ref[i] : to_string(i + 1);
            pq.pop();
            i++;
        }

        return res;
    }
};