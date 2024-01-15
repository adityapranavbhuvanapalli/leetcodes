class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> incoming;
        unordered_set<string> recipeList(recipes.begin(), recipes.end());
        vector<string> res;
        queue<string> q;

        for(int i=0; i<n; i++) {
            for(const auto& ingredient: ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
                incoming[recipes[i]]++;
            }
        }

        for(const auto& supply: supplies) {
            incoming[supply] = 0;
            q.push(supply);
        }

        while(q.size()) {
            auto& cur = q.front();
            
            if(recipeList.count(cur))
                res.push_back(cur);

            for(const auto& adj: graph[cur]) {
                if(--incoming[adj] == 0)
                    q.push(adj);
            }

            q.pop();
        }

        return res;
    }
};