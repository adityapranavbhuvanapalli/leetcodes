class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size(), l, r, cur;
        queue<int> q;
        vector<int> visited(n, false);

        if(!arr[start])
            return true;

        // BFS
        q.push(start);
        visited[start] = true;
        while (q.size()) {
            cur = q.front();
            q.pop();

            l = cur - arr[cur];
            r = cur + arr[cur];

            if (l >= 0 && l < n && !visited[l]) {
                if (arr[l] == 0)
                    return true;

                visited[l] = true;
                q.push(l);
            }
            if (r >= 0 && r < n && !visited[r]) {
                if (arr[r] == 0)
                    return true;

                visited[r] = true;
                q.push(r);
            }
        }

        return false;
    }
};