class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), l = 1, r = 0, mid;

        for(const auto& pile: piles)
            r = max(r, pile);

        while(l < r) {
            mid = l + (r-l) / 2;

            if(possible(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    bool possible(vector<int>& piles, int mid, int h) {
        long hours = 0;
        for(const auto& pile: piles) {
            hours += ceil(pile / (double)mid);
        }

        return hours <= h;
    }
};

/*
h = 8
3   6   7   11
0   1   2   3


1   2   3   4   5   6   7   8
l           m               r
l           r
    l       r
        l   r
            l,r
*/