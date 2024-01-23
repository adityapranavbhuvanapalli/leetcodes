class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count = numCourses;
        vector<vector<int>> graph(numCourses);
        vector<int> incoming(numCourses);
        queue<int> q;

        // Make Adjacency Graph
        for(const auto& prerequisite: prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            incoming[prerequisite[0]]++;
        }

        // Initialise queue
        for(int i=0; i<numCourses; i++) {
            if(incoming[i] == 0)
                q.push(i);
        }

        // BFS
        while(q.size()) {
            int front = q.front();
            q.pop();

            count--;

            // Add some elements into the queue which have incoming as 0
            for(const auto& adj: graph[front]) {
                incoming[adj]--;
                if(incoming[adj] == 0)
                    q.push(adj);
            }
        }

        return count == 0;
    }
};


/*

2,3 
4,3
1,3

0-
1-
2-
3-1,2,4
4-
*/