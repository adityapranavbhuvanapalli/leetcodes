class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> groups(n + 1, -1);
        vector<vector<int>> dislikeGraph(n + 1);

        for(const auto& dislike: dislikes) {
            dislikeGraph[dislike[0]].push_back(dislike[1]);
            dislikeGraph[dislike[1]].push_back(dislike[0]);
        }

        for(int i=1; i<=n; i++) {
            if(groups[i] == -1 && !dfs(i, 0, dislikeGraph, groups))
                return false; 
        }

        return true;
    }

    bool dfs(int i, int grp, vector<vector<int>>& dislikeGraph, vector<int>& groups) {
        if(groups[i] != -1)
            return groups[i] == grp;

        groups[i] = grp;

        for(auto& adj: dislikeGraph[i]) {
            if(!dfs(adj, 1 - grp, dislikeGraph, groups))
                return false;
        }

        return true;
    }
};

/*
1->2, 3
2->4
*/