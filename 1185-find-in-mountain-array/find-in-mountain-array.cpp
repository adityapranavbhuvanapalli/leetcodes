/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeak(n, mountainArr);

        int lSearch = binarySearch(0, peak, mountainArr, target, true);
        if(lSearch != -1)
            return lSearch;

        return binarySearch(peak + 1, n-1, mountainArr, target, false);
    }

    int binarySearch(int l, int r, MountainArray& arr, int target, bool ascend) {
        int mid, midVal;

        while(l <= r) {
            mid = l + (r-l)/2;

            midVal = arr.get(mid);

            if(midVal == target)
                return mid;

            if(ascend) {
                if(midVal < target)
                    l = mid + 1;
                else    
                    r = mid - 1;
            } else {
                if(midVal > target)
                    l = mid + 1;
                else    
                    r = mid - 1;
            }
        }

        return -1;
    }

    int findPeak(int n, MountainArray& mountainArr) {
        int l = 0, r = n-1, mid;

        while(l < r) {
            mid = l + (r-l)/2;

            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

    // int findPeak(int n, MountainArray& mountainArr) {
    //     int l = 0, r = n-1, mid, peak = 0, midVal, peakElement = 0;

    //     while(l <= r) {
    //         mid = l + (r-l)/2;

    //         midVal = mountainArr.get(mid);

    //         cout<<midVal<<" ";

    //         if(mountainArr.get(mid) < mountainArr.get(mid + 1)) {
    //             l = mid + 1;
    //         } else {
    //             peakElement = mountainArr.get(peak);
    //             if(peakElement < midVal) {
    //                 peak = mid;
    //                 peakElement = midVal;
    //             }
    //             r = mid - 1;
    //         }
    //     }

    //     return peak;
    // }
};