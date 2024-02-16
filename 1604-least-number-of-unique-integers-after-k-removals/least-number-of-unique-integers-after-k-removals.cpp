class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        for(const auto& num: arr) 
            freq[num]++;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(const auto& [k, v]: freq)
            pq.push(v);
        
        while(pq.size()) {
            int top = pq.top();
            
            if(k < top)
                break;

            k -= top;
            pq.pop();
        }

        return pq.size();
    }
};

/*
Remove the smallest frequency first
Store frequencies in a minHeap and keep popping until it is not possible to remove
*/