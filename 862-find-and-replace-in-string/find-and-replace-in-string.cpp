class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int i = 0, idx=0, n = s.size(), k = sources.size();
        map<int, vector<pair<string, string>>> data;

        for(int i=0; i<k; i++)
            data[indices[i]].push_back({sources[i], targets[i]});

        for(const auto& [k, vec]: data) {
            for(const auto& [src, tar]: vec) {
                indices[i] = k;
                sources[i] = src;
                targets[i] = tar;
                i++;
            }
        }

        int unprocessed = indices[k - 1];

        // for(int i=0; i<k; i++)
        //     cout<<indices[i]<<": "<<sources[i]<<" --> "<<targets[i]<<endl;

        for(int i=k-1; i>=0; i--) {
            int idx = indices[i];
            
            if(idx > unprocessed)
                continue;

            if(n - idx + 1 < sources[i].size())
                continue;

            if(s.substr(idx, sources[i].size()) != sources[i])
                continue;

            // Replace source with target
            s.replace(idx, sources[i].size(), targets[i]);
            unprocessed = idx - 1;
        }

        return s;
    }
};

/*
vmokgggqzp
0123456789

1: mo --> bfr
3: kg --> s
5: ggq --> so


abcdef
012345

2: feg --> abc
2: cdef --> feg
*/