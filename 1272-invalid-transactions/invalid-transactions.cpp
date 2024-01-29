class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int count, n = transactions.size();
        vector<string> names(n), cities(n), res;
        vector<int> times(n), costs(n);
        unordered_set<int> invalids;

        string part = "";

        for(int i=0; i<n; i++) {
            part = "";
            count = 0;
            for(const auto& ch: transactions[i]) {
                if(ch != ',') {
                    part += ch;
                    continue;
                }
                if(count == 0) {
                    names[i] = part;
                } else if(count == 1) {
                    times[i] = stoi(part);
                } else if(count == 2) {
                    costs[i] = stoi(part);
                } 
                part = "";
                count++;
            }

            cities[i] = part;

            // cout<<i<<": "<<names[i]<<", "<<times[i]<<", "<<costs[i]<<", "<<cities[i]<<endl;
        }

        for(int i=0; i<n; i++) {
            if(costs[i] >= 1000) 
                invalids.insert(i);

            for(int j=i+1; j<n; j++) {
                if(names[i] == names[j] && abs(times[i] - times[j]) <= 60 && cities[i] != cities[j]) {
                    // cout<<i<<","<<j<<endl;
                    invalids.insert(i);
                    invalids.insert(j);    
                }
            }    
        }

        for(const auto& i: invalids) {
            res.push_back(transactions[i]);
        }

        return res;
    }
};