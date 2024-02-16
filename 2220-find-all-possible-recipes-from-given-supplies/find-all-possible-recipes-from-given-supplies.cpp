class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> res;
        unordered_set<string> recipeSet(recipes.begin(), recipes.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> incoming;
        queue<string> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<ingredients[i].size(); j++) {
                incoming[recipes[i]]++;
                graph[ingredients[i][j]].push_back(recipes[i]);
            }
        }

        // Topological Sort
        for(auto& supply: supplies)
            q.push(supply);

        while(q.size()) {
            auto& cur = q.front();

            if(recipeSet.count(cur))
                res.push_back(cur);

            for(auto& adj: graph[cur]) {
                incoming[adj]--;
                if(incoming[adj] == 0) {
                    q.push(adj);
                }
            }

            q.pop();
        }

        return res;
    }
};