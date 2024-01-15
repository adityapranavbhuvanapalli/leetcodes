class Solution {
public:
    struct Compare {
        bool operator()(auto& l, auto& r) {
            return l.first == r.first ? l.second > r.second : l.first > r.first;
        }
    };

    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        unordered_set<int> marked;

        for(int i=0; i<n; i++)
            pq.push({nums[i], i});

        while(pq.size()) {
            while(pq.size() && marked.count(pq.top().second))
                pq.pop();
            

            if(pq.empty())
                break;

            score += pq.top().first;
            marked.insert(pq.top().second);
            marked.insert(pq.top().second - 1);
            marked.insert(pq.top().second + 1);

            pq.pop();
        }

        return score;
    }
};