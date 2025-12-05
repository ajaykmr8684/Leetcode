class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;

        for(auto it: nums) totalSum += it;

        int leftSum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size()-1; ++i) {
            leftSum += nums[i];
            int rightSum = totalSum - leftSum;

            if((leftSum - rightSum) % 2 == 0 ) ans++;
        }

        return ans;
    }
};