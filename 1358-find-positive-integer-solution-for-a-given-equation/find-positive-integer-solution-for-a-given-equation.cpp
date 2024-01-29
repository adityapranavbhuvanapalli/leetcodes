/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int y;

        for(int x=1; x<=z; x++) {
            y = binary(x, z, customfunction);
            if(y != -1)
                res.push_back({x, y});
        }

        return res;
    }

    int binary(int x, int z, CustomFunction& customfunction) {
        int l = 1, r = z, mid, res;

        while(l <= r) {
            mid = l + (r - l) / 2;

            res = customfunction.f(x, mid);
            if(res == z) 
                return mid;

            if(res < z)
                l = mid + 1;
            else 
                r = mid - 1;
        }

        return -1;
    }
};

/*
All (x, y) such that f(x, y) = z

f(x, y) = z
x y
1,1 == p
.
.   == z
.      .
.      .
.   == z
.
z,z = q
*/