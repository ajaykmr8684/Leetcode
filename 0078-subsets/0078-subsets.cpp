class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums, int i, vector<int> &s) {
        if(i == nums.size()) {
            result.push_back(s);
            return;
        }
        s.push_back(nums[i]);
        solve(nums, i+1, s);
        s.pop_back();
        solve(nums, i+1, s);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> s;
       solve(nums, 0, s);
       return result; 
    }
};