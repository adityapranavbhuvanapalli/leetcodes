class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), tmp = 0;
        for(int i=0; i<n1; i++) {
            for(int j=tmp; j<n2; j++) {
                if(nums2[j] > nums1[i]) {
                    tmp = j;
                    break;
                }
                if(nums1[i] == nums2[j])
                    return nums1[i];
            }
        }
        
        return -1;
    }
};