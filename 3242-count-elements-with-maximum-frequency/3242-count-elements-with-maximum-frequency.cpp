class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it: nums) {
            mp[it]++;
        }

        //Get the max frequency.
        int maxi = 0;
        for(auto it: mp) {
            maxi = max(maxi, it.second);
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