class Solution {
public:
    void solve(vector<int>& nums, int start, vector<vector<int>> &result) {
        if(start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            solve(nums, start+1, result);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, 0, result);
        return result;
    }
};