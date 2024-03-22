class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        vector<int> res;

        while(r - l + 1 > k) {
            if(abs(arr[r] - x) >= abs(arr[l] - x))
                r--;
            else 
                l++;
        }

        for(int i=l; i<=r; i++)
            res.push_back(arr[i]);
    
        return res;
    }
};