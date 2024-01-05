class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<pair<int, int>> s;
        vector<int> pre;
        string node = "";
        preorder += ',';
        for(const auto& ch: preorder) {
            if(ch != ',') {
                node += ch;
                continue;
            }

            if(node == "#")
                pre.push_back(-1);
            else
                pre.push_back(stoi(node));
            node = "";
        }

        int n = pre.size();

        if(pre[0] != -1)
            s.push({pre[0], 0});
            
        for(int i=1; i<n; i++) {
            if(s.size() == 0)
                return false;

            if(pre[i] != -1) {
                s.push({pre[i], 0});
                continue;
            } 
            
            s.top().second++;

            while(s.size() && s.top().second == 2) {
                s.pop();
                if(s.size())
                    s.top().second++;
            }
        }

        return s.size() == 0;
    }
};