class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size(), count;
        set<vector<int>> uniq;

        for(int i=0; i<n; i++) {
            vector<int> comb;
            count = 0;
            for(int j=i; j<n; j++) {
                if(nums[j] % p == 0)
                    count++;

                if(count > k)
                    break;

                comb.push_back(nums[j]);
                uniq.insert(comb);
            }
        }

        return uniq.size();
    }
};

/*
k = 2, p = 2

count = 5

2   3   3   2   2
i
                j
    i
                    j
        i
                    j
            i
                    j
                i
                    j
*/