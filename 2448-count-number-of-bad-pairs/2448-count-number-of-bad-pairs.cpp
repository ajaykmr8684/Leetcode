class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        long long n = nums.size();

        for(int i = 0; i < n; ++i) {
            nums[i] = nums[i] - i;
        }

        unordered_map<int, int> umap;

        for(int j = 0; j < n; ++j) {
            long long pairs = j - umap[nums[j]];
            badPairs += pairs;
            umap[nums[j]]++;
        }

        return badPairs;
    }
};