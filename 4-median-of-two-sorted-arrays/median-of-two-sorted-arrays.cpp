class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int total = n1 + n2;
        int half = ceil(total / 2.0);

        int l = 0, r = n1, mid1, mid2;

        while(l <= r) {
            mid1 = l + (r - l) / 2;
            mid2 = half - mid1;

            int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int right1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int right2 = (mid2 < n2) ? nums2[mid2] : INT_MAX; 

            if(left1 <= right2 && left2 <= right1) {
                if(total % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;

                return max(left1, left2);
            } else if(left1 > right2) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }

        return -1;
    }
};

/*
                    l1  r1
-&  1   2   3   4   5 | &
                   -& | 6   7   8   9   &
                   l2   r2

1   2   3   4   5
6   7   8   9

half = ceil(9 / 2)

*/