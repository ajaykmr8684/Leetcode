class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        unordered_map<int, int> freq;

        for(auto it: nums1) {
            freq[it] += nums2.size();
        }

        for(auto it: nums2) {
            freq[it] += nums1.size();
        }

        for(auto it: freq)
        {
            if(it.second % 2 != 0) {
                result ^= it.first;
            }
        }

        return result;

    }
};