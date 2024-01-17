class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        unordered_set<int> uniq;

        for (const auto& num : arr)
            count[num]++;

        for (const auto& [k, v] : count)
            if (!uniq.insert(v).second)
                return false;

        return true;
    }
};