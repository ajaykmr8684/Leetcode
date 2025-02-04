class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = nums[0];

        int total = nums[0];

        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] <= nums[i-1])
            {
                total = 0;
            }
            total += nums[i];
            cout << total << endl;
            maxi = max(total, maxi);
        }
        

        return maxi;
    }
};