class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), ng = goal.size(), count = 0;
        
        if(n != ng)
            return false;
        
        for(int i=0; i<n; i++) {
            count = 0;
            for(int j=0; j<n; j++) {
                if(s[(i+j) % n] != goal[j])
                    break;
                count++;
            }
            
            if(count == n)
                return true;
        }
        
        return false;
    }
};