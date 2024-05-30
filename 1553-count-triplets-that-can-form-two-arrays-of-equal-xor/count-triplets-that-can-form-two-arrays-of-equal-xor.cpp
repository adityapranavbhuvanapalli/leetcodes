class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), count = 0, prefix = 0;
        unordered_map<int, vector<int>> posOfL;

        for(int k=0; k<n; k++) {
            prefix = prefix ^ arr[k];

            if(prefix == 0) 
                count += k;

            for(const auto& i: posOfL[prefix])
                count += k - i - 1;
            
            posOfL[prefix].push_back(k);
        }

        return count;
    }
};
/*
Given
arr[i]...arr[j-1] = a
arr[j]...arr[k] = b
a == b

That means a ^ b == 0
arr[i] .... arr[k] = 0

Number of triplets that satisfy this between i and k the number of j's possible
But for XOR j can be possible everywhere between i and k so 
Number of triplets that satisfy this between i and k = k - i + 1

We can solve using prefix XOR

2   3   1   6   7

2   3   1
2   3   1
        1   6   7
        1   6   7
----------------------
1   1   1   1   1

1   1
    1   1
        1   1  
            1   1
1   1   1   1
1   1   1   1
1   1   1   1
    1   1   1   1
    1   1   1   1
    1   1   1   1

*/