class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int i = 0, idx=0, n = s.size(), k = sources.size();
        map<int, vector<pair<string, string>>> data;
        string res = "";

        for(int i=0; i<k; i++)
            data[indices[i]].push_back({sources[i], targets[i]});

        i = 0;
        for(const auto& [k, vec]: data) {
            for(const auto& [src, tar]: vec) {
                indices[i] = k;
                sources[i] = src;
                targets[i] = tar;
                i++;
            }
        }

        i = 0;
        while(i < n) {
            while(i < n && (idx >= k || i < indices[idx])) {
                res += s[i];
                i++;
            }

            if(i >= n)
                break;

            if(idx < k && s.substr(indices[idx], sources[idx].size()) == sources[idx]) {
                res += targets[idx];
                i += sources[idx].size(); 
            }

            idx++;
        }

        return res;
    }
};