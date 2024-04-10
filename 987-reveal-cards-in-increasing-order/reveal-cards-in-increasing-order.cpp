class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> positions(n, -1), res(n);

        queue<int> q;
        for(int i=0; i<n; i++) {
            q.push(i);
        }

        int i = 0;
        while(q.size()) {
            positions[i] = q.front();
            q.pop();
            int next = q.front();
            q.pop();
            q.push(next);
            i++;
        }

        for(int i=0; i<n; i++) {
            res[positions[i]] = deck[i]; 
        }

        return res;
    }
};

/*
17  13  11  2   3   5   7

Sort the array
2   3   5   7   11  13  17

2       3       5       7
    _       _       _

    13              11
            _

            17
*/