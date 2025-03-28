class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> temp(m+n);

        int k = 0;
        int i = 0;
        int j =0;

        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                temp[k] = nums1[i];
                i++;
            }
            else {
                temp[k] = nums2[j];
                j++;
            }
            k++;
        }

        while(i < m) {
            temp[k] = nums1[i];
            i++;
            k++;
        }

        while(j < n) {
            temp[k] = nums2[j];
            j++;
            k++;
        }

        int size = m + n;

        if(size % 2 == 1) {
            return temp[size/2];
        }
        
        return (temp[size/2] + temp[(size/2) - 1])/2.0;
    }
};