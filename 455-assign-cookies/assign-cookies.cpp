class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0, ng = g.size(), ns = s.size(), i = 0, j = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i < ng && j < ns) {
            if(s[j] >= g[i]) {
                count++;
                i++;
            }

            j++;
        }

        return count;
    }
};