class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;

        for(auto it: nums1) {
            sum1 += it;
            if(it == 0) {
                sum1 += 1;
                zero1++;
            }
        }

        for(auto it: nums2) {
            sum2 += it;
            if(it == 0) {
                sum2 += 1;
                zero2++;
            }
        }

        if(sum1 < sum2 && zero1 == 0) return -1;
        if(sum2 < sum1 && zero2 == 0) return -1;

        return max(sum1, sum2);

    }
};