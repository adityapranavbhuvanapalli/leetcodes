class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char, int> freq;
        priority_queue<int> pq;
        stack<int> rem;

        for (const auto& task : tasks)
            freq[task]++;

        for (const auto& [k, v] : freq)
            pq.push(v);

        while (pq.size()) {
            for (int i = 0; i <= n; i++) {
                if (pq.empty()) {
                    if (rem.size() > 0)
                        time += n - i + 1;
                    break;
                }

                time++;
                if (pq.top() > 1)
                    rem.push(pq.top() - 1);
                pq.pop();
            }

            while (rem.size()) {
                pq.push(rem.top());
                rem.pop();
            }
        }

        return time;
    }
};

/*
A - 3
B - 3

pq:
3

rem:
2

_   _   _
A   B   #
A   B   #
A   B   #
*/