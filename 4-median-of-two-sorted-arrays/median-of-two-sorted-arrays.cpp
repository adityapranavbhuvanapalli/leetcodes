class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > n2) 
            return findMedianSortedArrays(nums2, nums1);

        int total = n1 + n2, half = (total + 1) / 2;
        int l = 0, r = n1, mid1, mid2;
        while(l <= r) {
            mid1 = l + (r - l) / 2; // for nums1
            mid2 = half - mid1;

            int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int right1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int right2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

            if(left1 <= right2 && left2 <= right1) {
                // Odd case
                if(total % 2 == 1)
                    return max(left1, left2);

                // Even case
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else if(left1 > right2){
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        } 

        return -1;
    }
};

/*
1   4 | 9  16  25


3   5   7 | 13
    l           
            r
        m

1   3   4   5   7   9   13   16  25


11 |12  13  14  15
1   2   3   4 |
        l
            r
        m
*/