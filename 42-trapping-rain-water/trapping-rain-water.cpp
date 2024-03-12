class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1;
        int units = 0, maxL = 0, maxR = 0;

        while(l < r) {
            if(height[l] > maxL) {
                maxL = height[l];
            } else {
                units += (maxL - height[l]);
            }
        

            if(height[r] > maxR) {
                maxR = height[r];
            } else {
                units += (maxR - height[r]);
            }

            if(height[l] < height[r]) {
                l++;
            } else {
                r--;
            }    
        }

        return units;
    }
};

/*
0   1   0   2   1   0   1   3   2   1   2   1
    l
                                            r
*/