class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        for(auto it: nums) {
            mp[it]++;
            maxi = max(maxi, mp[it]);
        }

        //Find out how many elements have the max frequency.
        int ans = 0;
        for(auto num : nums) {
            if(mp.find(num) != mp.end() && mp[num] == maxi) {
                ans++;
            }
        }

        return ans;
    }
};