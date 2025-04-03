class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0;
        long long maxDiff = 0;
        long long result = 0;


        for(int i = 0; i < n; ++i) {
            result = max(result, maxDiff * nums[i]);
            maxDiff = max(maxDiff, maxi - nums[i]);
            maxi = max(maxi, (long long)nums[i]);
        }

        return result;
    }
};