class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char, int> freq;
        priority_queue<int> pq;
        stack<int> rem;

        for(const auto& task: tasks)
            freq[task]++;
    
        for(const auto& [k, v]: freq)
            pq.push(v);

        while(pq.size()) {
            // Select n tasks or wait if no tasks are there
            for(int i=0; i<=n; i++) {
                if(pq.empty()) {
                    if(rem.size())
                        time += n - i + 1;
                    // cout<<n<<":"<<i<<" ";
                    break;
                }

                if(pq.top() > 1)
                    rem.push(pq.top() - 1);
                pq.pop();

                time++;
                // cout<<rem.top()<<":"<<time<<":"<<rem.size()<<" --- ";

            }

            // cout<<" ----> "<<time<<endl;
            while(rem.size()) {
                pq.push(rem.top());
                rem.pop();
            }
        }

        return time;
    }
};