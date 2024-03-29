class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;

        for(const auto& weight: weights) {
            l = max(l, weight);
            r += weight;
        }

        while(l < r) {
            int mid = l + (r - l) / 2;

            int sum = 0, taken = 1;
            for(const auto& weight: weights) {
                if(sum + weight <= mid)
                    sum += weight;
                else {
                    taken++;
                    sum = weight;
                }
            }

            if(taken <= days) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};

/*
days = 5

10  20  .......     54  55
l
                        r

Identify the first version where it is possible
*/