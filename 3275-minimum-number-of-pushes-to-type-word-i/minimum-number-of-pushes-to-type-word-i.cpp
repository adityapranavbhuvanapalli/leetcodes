class Solution {
public:
    int minimumPushes(string word) {
        int res = 0, n = word.size(), count = 0; 
        
        while(n > 0) {
            count++;
            res += min(n, 8) * count;
            n = n - 8;
        }
        
        return res;
    }
};