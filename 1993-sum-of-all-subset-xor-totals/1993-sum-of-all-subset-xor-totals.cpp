class Solution {
public:
    int solve(vector<int>& nums, int i, int Xor) {

        if(i == nums.size()) {
            return Xor;
        }
        int take = solve(nums, i+1, Xor^nums[i]);
        int not_take = solve(nums, i+1, Xor);

        return take + not_take;
    }
    int subsetXORSum(vector<int>& nums) {
       return solve(nums, 0, 0);
    }
};