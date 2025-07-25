class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for(auto it: st) {
            if(it > 0)
             ans += it;
        }
        if(ans == 0) ans = *max_element(st.begin(), st.end());

        return ans;
    }
};