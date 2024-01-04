class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> count;
        int val = 0;
        for(auto& task: tasks)
            count[task]++;
        
        for(auto& [key, freq]: count) {
            if(freq == 1)
                return -1;
            val += ceil(freq/3.0);
        }
            
        return val;
    }
};