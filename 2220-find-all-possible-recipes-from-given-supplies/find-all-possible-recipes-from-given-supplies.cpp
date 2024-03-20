class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> res;
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> incoming;
        queue<string> q;

        // Graph
        for(int i=0; i<n; i++) {
            for(const auto& ingredient: ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
                incoming[recipes[i]]++;
            }
        }

        for(const auto& supply: supplies)
            q.push(supply);

        // Topological Sort
        while(q.size()) {
            string front = q.front();
            q.pop();

            if(incoming.count(front) == 1)
                res.push_back(front);

            for(const auto& adj: graph[front]) {
                incoming[adj]--;
                if(incoming[adj] == 0) {
                    q.push(adj);
                }
            }
        }

        return res;
    }
};

/*
yeast - bread
flour - bread
bread - samdwich
meat - sandwich
*/