class Solution {
public:
    int solve(vector<int> nums, int target){
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] != target){
                nums[i] = -nums[i];
                nums[i+1] = -nums[i+1];
                cnt++;
            }
        }
        return nums[n-1] == target ? cnt : INT_MAX;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        return solve(nums, 1) <= k || solve(nums, -1) <= k;
    }
};