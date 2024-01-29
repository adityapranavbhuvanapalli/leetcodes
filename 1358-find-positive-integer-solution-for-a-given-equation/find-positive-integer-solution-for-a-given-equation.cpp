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

        for(int x=1; x<=z; x++) {
            for(int y=1; y<=z; y++) {
                if(customfunction.f(x, y) == z)
                    res.push_back({x, y});
            }
        }

        return res;
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