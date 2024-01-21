class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        int dist = 0, sz, cur;
        vector<vector<int>> mins(n, vector<int>(n, 0));
        vector<int> res(n, 0);
        
        x--, y--;
        
        for(int i=0; i<n; i++) {
            queue<int> q;
            vector<bool> visited(n, false);
            
            q.push(i);
            visited[i] = true;
            dist = 0;
            
            while(q.size()) {
                sz = q.size();
                while(sz--) {
                    auto cur = q.front();
                    q.pop();

                    mins[i][cur] = dist;
                        
                    if(cur == x && x != y && !visited[y]) {
                        q.push(y);
                        visited[y] = true;
                    }
                    
                    if(cur == y && y != x && !visited[x]) {
                        q.push(x);
                        visited[x] = true;
                    }
                    
                    if(cur < n-1 && !visited[cur + 1]) {
                        q.push(cur + 1);
                        visited[cur + 1] = true;
                    }
                    
                    if(cur > 0 && !visited[cur - 1]) {
                        q.push(cur - 1);
                        visited[cur - 1] = true;
                    }
                }
                dist++;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mins[i][j] > 0)
                    res[mins[i][j] - 1]++;
            }
        }
        
        return res;
    }
};