class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> st;
    void solve(vector<int>& nums, int i, vector<int> &s) {
            if(i == nums.size()) {
                if (st.find(s) == st.end()) {
                result.push_back(s);
                st.insert(s);
            }
                return;
            }

            s.push_back(nums[i]);
            solve(nums, i+1, s);
            s.pop_back();
            solve(nums, i+1, s);
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> s;
        sort(nums.begin(), nums.end());
        solve(nums, 0, s);
        return result;
    }
};