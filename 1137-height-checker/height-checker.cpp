class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0, n = heights.size();
        vector<int> ne(heights);
        sort(ne.begin(), ne.end());
        for(int i=0; i<n; i++) {
            count += (ne[i] != heights[i]);
        }
        
        return count;
    }
};