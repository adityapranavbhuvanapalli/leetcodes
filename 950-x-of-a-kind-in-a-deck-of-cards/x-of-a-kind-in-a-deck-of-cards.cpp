class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int x = -1;
        unordered_map<int, int> count;

        for(const auto& d: deck)
            count[d]++;

        for(const auto& [k, v]: count) {
            if(x == -1) {
                x = v;
                continue;
            }

            x = __gcd(x, v);
        }

        return x > 1;
    }
};