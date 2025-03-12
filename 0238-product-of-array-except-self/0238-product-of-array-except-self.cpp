class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n = nums.size();

        ans[0] = 1;

        for(int i = 1; i < nums.size(); ++i)
        {
           ans[i] = ans[i-1] * nums[i-1];
        }

        int right_product = 1;
        for(int i = n - 1; i >= 0; --i)
        {
           ans[i] = ans[i] * right_product;
           right_product *= nums[i];
        }

        return ans;
    }
};