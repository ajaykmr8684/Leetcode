class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;
        int ans = INT_MIN;

        int sum = 0;
        while(j < n) {
            mp[nums[j]]++;
            while(mp[nums[j]] > 1) {
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            sum += nums[j];
            ans = max(sum, ans);
            j++;
        }

        return ans;
    }
};