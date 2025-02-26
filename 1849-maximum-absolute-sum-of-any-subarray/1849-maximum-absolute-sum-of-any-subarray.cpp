class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSubSum = nums[0];
        int currSubSum = nums[0];

        for(int i = 1; i < nums.size(); ++i) {
            currSubSum = max(nums[i], currSubSum + nums[i]);
            maxSubSum = max(maxSubSum, currSubSum);
        }

        int minSubSum = nums[0];
        currSubSum = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            currSubSum = min(nums[i], currSubSum + nums[i]);
            minSubSum = min(minSubSum, currSubSum);
        }

        return max(maxSubSum, abs(minSubSum));


    }
};