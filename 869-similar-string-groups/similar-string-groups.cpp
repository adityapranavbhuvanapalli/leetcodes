class Solution {
public:
    vector<int> root;
    int components;
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        root.resize(n);
        components = n;

        for(int i=0; i<n; i++)
            root[i] = i;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(isChild(strs[i], strs[j])) {
                    unite(i, j);
                }
            }
        }

        return components;
    }

    bool isChild(string& s1, string& s2) {
        if(s1 == s2)
            return true;

        int n = s1.size();
        int i1 = -1, i2 = -1, count = 0;
        for(int i=0; i<n; i++) {
            if(s1[i] == s2[i]) 
                continue;

            if(count == 2)
                return false;

            count++;
            if(i1 == -1)
                i1 = i;
            else 
                i2 = i;
        }

        return (s1[i1] == s2[i2]) && (s1[i2] == s2[i1]);
    }

    void unite(int a, int b) {
        int findA = find(a), findB = find(b);

        if(findA != findB) {
            root[max(findA, findB)] = min(findA, findB);
            components--;
        }
    }

    int find(int i) {
        return root[i] = (root[i] != i) ? find(root[i]) : i;
    }
};

/*
tars
rats
arts
star
*/