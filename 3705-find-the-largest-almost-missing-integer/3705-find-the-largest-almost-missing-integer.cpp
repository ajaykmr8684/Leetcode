class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto it: nums) freq[it]++;

        int uniqueLargest = -1, largest = -1, ans = -1;
        for(int i = 0; i < nums.size(); ++i) {
            if(freq[nums[i]] == 1) uniqueLargest = max(uniqueLargest, nums[i]);
            largest = max(largest, nums[i]);
        }

        if(k == 1) return uniqueLargest;
        if(k == nums.size()) return largest;
        if(freq[nums[0]] == 1) ans = max(ans, nums[0]);
        if(freq[nums.back()] == 1) ans = max(ans, nums.back());

        return ans;
    }
};