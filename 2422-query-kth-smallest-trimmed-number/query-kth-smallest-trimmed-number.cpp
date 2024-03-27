class Solution {
public:
    typedef pair<string, int> T;

    struct Compare {
        bool operator()(auto& l, auto& r) {
            return (l.first == r.first) ? l.second < r.second : l.first < r.first;
        }
    };

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> res;

        for(const auto& query: queries) {
            priority_queue<T, vector<T>, Compare> pq;
            for(int i=0; i<n; i++) {
                pq.push({nums[i].substr(nums[i].size() - query[1]), i});
                if(pq.size() > query[0])
                    pq.pop();
            }

            res.push_back(pq.top().second);
        }

        return res;
    }
};

/*
102     473     251     814
2       3       1       4


4   7   6   4

*/