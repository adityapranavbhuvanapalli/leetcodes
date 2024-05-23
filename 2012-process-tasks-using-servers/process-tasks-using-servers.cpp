class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int i = 0, nServers = servers.size(), nTasks = tasks.size(), time = 0;
        vector<int> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> busyServers;     //{busyTime, idx}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> freeServers;     //{weight, idx}
        
        for(int i=0; i<nServers; i++)
            freeServers.push({servers[i], i});

        while(i < nTasks) {
            // Shifting freed servers from busyServers to freeServers
            while(busyServers.size() && busyServers.top()[0] <= time) {
                int x = busyServers.top()[1];
                freeServers.push({servers[x], x});
                busyServers.pop();
            }

            // Assigning all available tasks before time to available servers
            while(freeServers.size() && i < nTasks && i <= time) {
                int idx = freeServers.top()[1];
                busyServers.push({time + tasks[i], idx});
                res.push_back(idx);
                freeServers.pop();
                i++;
            }

            if(freeServers.size()) {
                time++;
            } else {
                time = busyServers.top()[0];
            }
        }

        return res;
    }
};