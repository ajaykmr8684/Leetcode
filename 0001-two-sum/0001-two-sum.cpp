class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans(2);

        for(int i = 0; i < nums.size(); ++i) {
            if(mp.find(target - nums[i]) != mp.end()) {
                return {mp[target-nums[i]], i};
            }
            else mp[nums[i]] = i;
        }

        return ans;
    }
};