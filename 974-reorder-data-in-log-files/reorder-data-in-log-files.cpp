class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        string part;
        vector<vector<string>> transform;
        unordered_map<string, int> idx;

        int i=0;
        for(auto& s: logs) {
            part = "";
            idx[s] = i;
            transform.push_back({});
            auto& b = transform.back();
            for(const auto& ch: s) {
                if(ch != ' ') {
                    part += ch;
                    continue;
                }

                b.push_back(part);
                part = "";
            }
            b.push_back(part);
            part = "";

            isalpha(b[1][0]) ? b.push_back("-") : b.push_back(to_string(i));
            i++;
        }

        sort(logs.begin(), logs.end(), [&](auto& l, auto& r) {
            vector<string> sl =  transform[idx[l]], sr =  transform[idx[r]];
            int nl = sl.size(), nr = sr.size();

            if(sl[nl-1] != "-" && sr[nr-1] != "-")
                return stoi(sl[nl-1]) < stoi(sr[nr-1]);

            if(sl[nl-1] != "-")
                return false;
            if(sr[nr-1] != "-")
                return true;
            
            for(int i=1; i<min(nl, nr) - 1; i++) {
                if(sl[i] > sr[i])
                    return false;

                if(sl[i] < sr[i])   
                    return true;
            }

            if(nl == nr)
                return sl[0] < sr[0];

            return nl < nr;
        });

        return logs;
    }
};