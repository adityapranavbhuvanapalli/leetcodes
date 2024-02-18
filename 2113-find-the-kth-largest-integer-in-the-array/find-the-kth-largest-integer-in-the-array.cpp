class Solution {
public:
    struct Compare {
        bool operator()(string& l, string& r) {
            return l.size() == r.size() ? l > r : l.size() > r.size();
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, Compare> pq;

        for(const auto& num: nums) {
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};

/*
n log n


*/