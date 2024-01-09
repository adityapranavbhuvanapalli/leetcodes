class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n2 = arr2.size();
        unordered_map<int, int> priority;
        
        for(int i=0; i<n2; i++)
            priority[arr2[i]] = n2-i;
        
        sort(arr1.begin(), arr1.end(), [&](auto& l, auto& r) {
            return priority[l] == priority[r] ? l < r : priority[l] > priority[r];
        });
        
        return arr1;
    }
};