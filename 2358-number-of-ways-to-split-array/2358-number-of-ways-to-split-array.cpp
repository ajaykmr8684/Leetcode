class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;


        long totalSum = 0;
        for(auto it: nums)
        {
            totalSum += it;
        }

        long leftSum = 0;
        long rightSum = 0;
        for(int i = 0; i < n-1; ++i)
        {
            leftSum += nums[i];
            rightSum = totalSum - leftSum;

            if(rightSum <= leftSum) ans++;
        }

        return ans;
    }
};